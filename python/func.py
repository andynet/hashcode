def evaluate(endpoints,video_id,cache_id):
    """Calculate how many ms will safe video in cache_id

    :endpoints: Dictionary of Endpoints
    :video_id: id of video
    :cache_id: id of cache 
    :returns: miliseconds

    """
    ret = 0

    for endpoint in endpoints:
        if cache_id not in map(lambda x:int(x[0]),endpoint['l_cache_s']):
            continue

        for request in endpoint['requests']:
            if request['video_id']==video_id:
                ret+=(endpoint['l_data_c']-endpoint['l_cache_s'][cache_id])*request['count']

    return ret

