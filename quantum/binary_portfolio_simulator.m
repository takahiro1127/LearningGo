%%% iteratedDWaveRuns_MeanVar_WMIS_compositeF
%
% PURPOSE: Perform iterations over the stock data using the D-Wave
% hardware optimization engine.
% Use Mean-Variance with WMIS optimizing F.
% Author: Michael Marzec, Stevens Institute of Technology
% the filename containing our stored data...
loadfile = 'myHistoricalStockData-20130408.mat';
% load the data from the file
load(loadfile, 'histData');
dataSize = size(histData(1).adjClse); % number of stocks retrieved
% Vector of our stock names...
% use Cell Array '{}'
Stocks = {...
        histData(1).symbol{1}; ...
        histData(2).symbol{1}; ...
        histData(3).symbol{1}; ...
        histData(4).symbol{1}; ...
        histData(5).symbol{1}; ...
        histData(6).symbol{1}; ...
        histData(7).symbol{1}; ...
        histData(8).symbol{1}; ...
        histData(9).symbol{1}; ...
        histData(10).symbol{1} ...
        };
% -------------------------------------------------
% create a single Prices matrix from our structures
% -------------------------------------------------
% For each column...
for k = 1:10
    % For each row...
    for i = 1:size(histData(k).adjClse)

        Prices(i, k) = histData(k).adjClse(i);

    end

end

% ----------------------------------
% Need to calculate the log returns
% ----------------------------------
logReturns = diff(log(Prices));
% Average log-return for each stock
avgLogReturns = mean(logReturns, 1);
% ----------------------------------------------------------------
% Calculate the Variance-Covariance between pairs of stock log returns...
% ----------------------------------------------------------------
% Need the var/covar matrix...
covLogReturns = cov(logReturns);
% ...we'll use the Variance of the logReturns, as well...
varLogReturns = var(logReturns);
% ...also need the stdDev
stdDevLogReturns = sqrt(varLogReturns);
% a visualization of the Var-Covar...
bar(covLogReturns), xlabel('Stocks'), ylabel('Var-Covar'), legend(Stocks);
% ------------------------------------------
% Static variables/set-up for the D-Wave run
%
% Specify the embedding list...
% Adapted from D-Wave's K17_Q128_EMBEDDING
% ------------------------------------------
K10_Q128_EMBEDDING = cell(1, 10);
K10_Q128_EMBEDDING{1} = [0 4 12 20 28];
K10_Q128_EMBEDDING{2} = [1 5 13 21 29];
K10_Q128_EMBEDDING{3} = [2 6 14 22 30];
K10_Q128_EMBEDDING{4} = [3 7 15 23 31];
K10_Q128_EMBEDDING{5} = [8 40 44 52 60];
K10_Q128_EMBEDDING{6} = [9 41 45 53 61];
K10_Q128_EMBEDDING{7} = [10 42 46 54 62];
K10_Q128_EMBEDDING{8} = [11 43 47 55 63];
K10_Q128_EMBEDDING{9} = [16 48 80 84 92];
K10_Q128_EMBEDDING{10} = [17 49 81 85 93];
% The J parameter used here; must be any real number > 1
% Note: this re-uses the normJ from the equal-weight example
% Actual condition for selecting normJ is: normJ > min{c_i, c_j}
normJ = 1.1;

% -----------------------------------------------------------------
% Here is the connectivity to the local or remote D-Wave solvers...
% -----------------------------------------------------------------
% Get a connection to the local solver...
conn = sapiLocalConnection();
% Get a list of solvers available locally...
solvers = sapiListSolvers(conn);
% Print the list of solvers available...
solvers
% create a handle to a particular solver
solver = sapiSolver(conn, 'c4-sw_optimize');
% Create the embedding solver
embeddingSolver = sapiEmbeddingSolver(solver, K10_Q128_EMBEDDING);
% ---------------------------------------------------
% Re-used parameters from correlation-based runs:
% Iteration over various correlation threshold values
% from correlation = 0.35 to 0.65 by 0.05
% ---------------------------------------------------
% ------------------------------------------
% Generate a market graph...
% ------------------------------------------
isingSolutions = zeros(length(covLogReturns), 7);
% Init the optimumPortfolios array; this is a fast way - not the best.
optimumPortfolios = cell(10, 7);
loopCount = 1;

for cThresh = 0.35:0.05:0.65

    % correlations are used to set up the graph
    marketGraph = covLogReturns;

    % iterate through our initial graph and determine Edges
    for m = 1:length(marketGraph)
        % determine connectivity using our threshold
        for n = 1:length(marketGraph)
            % connect or not connect pairs based on threshold
            if m == n
                marketGraph(m, n) = 0;
            elseif abs(marketGraph(m, n)) > cThresh * stdDevLogReturns(m) * stdDevLogReturns(n)
                marketGraph(m, n) = 1;
            else
                marketGraph(m, n) = 0;
            end

        end

    end

    % print the market graph for each iteration
    cThresh
    marketGraph

    % count the number of edges for each stock node
    edgeCount = sum(marketGraph, 2);

    % ----------------------------------------------------
    % Calculate the Ising parameters...
    % Note: Here, node weights are the (return - variance)
    % values for each stock, ie node.
    % ----------------------------------------------------

    % the h_ij values
    for p = 1:length(edgeCount)
        % This uses the variance handicapped returns expressed in F
        hValues(p) = normJ * edgeCount(p) - 2 * (avgLogReturns(p) - varLogReturns(p));
    end

    % the J_ij values
    JValues = normJ * marketGraph;

    % Solve the Chimera-structured Ising problem
    answerIsing = sapiSolveIsing(embeddingSolver, hValues, JValues);

    for t = 1:length(answerIsing.solutions)

        if answerIsing.solutions(t) == 1
            %optimumPortfolios(t,loopCount) = Stocks(t);
            optimumPortfolios(t, loopCount) = java.lang.String(Stocks(t));
        else
            optimumPortfolios(t, loopCount) = java.lang.String('');
        end

    end

    % add to a matrix of solutions
    isingSolutions(:,loopCount) = answerIsing.solutions;

    loopCount = loopCount + 1;

    %gplot(marketGraph, [1 1; 2 4; 3 2; 4 8; 5 5; 6 10; 7 7; 8 3; 9 9; 10 6], '-*')

end
% print the optimum portfolios
optimumPortfolios
% -----------
% THE END
% -----------