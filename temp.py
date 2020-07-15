def prepare_app_data(df):
    df = extract_time_features(df)
    joinbase = df.groupby(['installation_id', 'game_session'], as_index=False, sort=False).agg(
        {'event_count': 'max', 'game_time': 'max'})
#アプリ毎のイベント発火回数の合計、平均、　ゲーム時間の合計と平均を取っている
    join1 = joinbase.groupby('installation_id', as_index=False, sort=False).agg(
        {'event_count': ['sum', 'mean'], 'game_time': ['sum', 'mean']})
#     print(join1)
#typeごとのプレイ時間
    joinbase = df.groupby(['installation_id', 'game_session', 'type'],
                          as_index=False, sort=False).agg({'game_time': 'max'})
    join2 = joinbase.groupby(['installation_id', 'type'], as_index=False, sort=False).agg(
        {'game_time': ['mean', 'sum']})
    print(join2.head())
#worldごとのプレイ時間
    joinbase = df.groupby(['installation_id', 'game_session', 'world'],as_index=False,sort=False).agg({'game_time': 'max'})
    join3 = joinbase.groupby(['installation_id', 'world'],as_index=False,sort=False).agg({'game_time': 'mean'})
#集計
    labels = ['installation_id', 'app_event_count_sum', 'session_event_count_mean', 'app_game_time_sum', 'session_game_time_sum', 'MAGMAPEAK_game_time_sum',
              'CRYSTALCAVES_game_time_sum', 'TREETOPCITY_game_time_sum', 'Clip_session_time_sum', 'Clip_session_time_mean', 'Activity_session_time_mean', 'Activity_session_time_sum',
              'Assessment_session_time_mean', 'Assessment_session_time_sum', 'Game_session_time_mean', 'Game_session_time_sum']
    result = pd.DataFrame(columns=labels)
    for ins_id in df['installation_id'].drop_duplicates():
        tmp = pd.DataFrame(columns=labels)
        tmp['installation_id'] = join1[join1.installation_id == ins_id]['installation_id']
        tmp['app_event_count_sum'] = join1[join1.installation_id == ins_id]['event_count']['sum']
        tmp['session_event_count_mean'] = join1[join1.installation_id == ins_id]['event_count']['mean']
        tmp['app_game_time_sum'] = join1[join1.installation_id == ins_id]['game_time']['sum']
        tmp['session_game_time_sum'] = join1[join1.installation_id == ins_id]['game_time']['mean']
        tmp['Clip_session_time_mean'] = join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Clip')].iloc[0]['game_time']['mean'] if (
            len(join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Clip')]) != 0) else 0
        tmp['Clip_session_time_sum'] = join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Clip')].iloc[0]['game_time']['sum'] if (
            len(join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Clip')]) != 0) else 0
        tmp['Activity_session_time_mean'] = join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Activity')].iloc[0]['game_time']['mean'] if (
            len(join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Activity')]) != 0) else 0
        tmp['Activity_session_time_sum'] = join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Activity')].iloc[0]['game_time']['sum'] if (
            len(join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Activity')]) != 0) else 0
        tmp['Assessment_session_time_mean'] = join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Assessment')].iloc[0]['game_time']['mean'] if (
            len(join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Assessment')]) != 0) else 0
        tmp['Assessment_session_time_sum'] = join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Assessment')].iloc[0]['game_time']['sum'] if (
            len(join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Assessment')]) != 0) else 0
        tmp['Game_session_time_mean'] = join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Game')].iloc[0]['game_time']['mean'] if (
            len(join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Game')]) != 0) else 0
        tmp['Game_session_time_sum'] = join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Game')].iloc[0]['game_time']['sum'] if (
            len(join2.loc[(join2.installation_id == ins_id) & (join2.type == 'Game')]) != 0) else 0
        tmp['CRYSTALCAVES_game_time_sum'] = join3.loc[(join3.installation_id == ins_id) & (join3.world == 'CRYSTALCAVES')].iloc[0]['game_time'] if (
            len(join3.loc[(join3.installation_id == ins_id) & (join3.world == 'CRYSTALCAVES')]) != 0) else 0
        tmp['TREETOPCITY_game_time_sum'] = join3.loc[(join3.installation_id == ins_id) & (join3.world == 'TREETOPCITY')].iloc[0]['game_time'] if (
            len(join3.loc[(join3.installation_id == ins_id) & (join3.world == 'TREETOPCITY')]) != 0) else 0
        tmp['MAGMAPEAK_game_time_sum'] = join3.loc[(join3.installation_id == ins_id) & (join3.world == 'MAGMAPEAK')].iloc[0]['game_time'] if (
            len(join3.loc[(join3.installation_id == ins_id) & (join3.world == 'MAGMAPEAK')]) != 0) else 0
        result = result.append(tmp, ignore_index=True)
    return result
