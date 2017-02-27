def evaluate(endpoints,video_id,cache_id):
    """Calculate how many ms will safe video in cache_id
    nekontroluje ci sa zmesti do Cache
    :endpoints: Dictionary of Endpoints
    :video_id: id of video
    :cache_id: id of cache 
    :returns: miliseconds

    """
    ret = 0

    for endpoint in endpoints:
        #print(endpoint)
        if cache_id not in map(lambda x:int(x[0]),endpoint['l_cache_s']):
            continue
        """
        for request in endpoint['requests']:
            if request['video_id']==video_id:
                ret+=(endpoint['l_data_c']-endpoint['l_cache_s'][cache_id])*request['count']
        """
        #lepsia verzia lebo cez to netreba iterovat
        video_ids = list(map(lambda x:x['video_id'], endpoint['requests']))
        if video_id in video_ids:
            cache_ids = dict(endpoint['l_cache_s'])
            index = video_ids.index(video_id)
            ret+=(endpoint['l_data_c']-cache_ids[cache_id])*endpoint['requests'][index]['count']

    return ret

