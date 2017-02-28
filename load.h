#pragma once 
#include <iostream>
#include <vector>
#include <unordered_map>
//co obsahuje endpoint
/*
struct request {
    long video_id;
    long count;

};
*/
struct endpoint {
    long l_data_c;
    long connections;
    //std::vector<std::pair<int,int>> l_cache_s;
    std::unordered_map<long,long> l_cache_s;
    std::unordered_map<long,long> requests;
};
/*
struct cache {
    long memory;
    std::vector<long> indexes;
};
*/
struct google_input {
    long num_videos;
    long num_endpoints;
    long num_requests;
    long num_caches;
    long caches_size;

    //std::vector<cache> caches;
    std::vector<endpoint> endpoints;
    std::vector<long> videos_size;
};

google_input read_input();


