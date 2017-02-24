#pragma once 
#include <iostream>
#include <vector>
//co obsahuje endpoint
struct request {
    int video_id;
    int count;

};

struct endpoint {
    int l_data_c;
    int connections;
    std::vector<std::pair<int,int>> l_cache_s;
    std::vector<request> requests;
};

struct cache {
    int memory;
    std::vector<int> indexes;
};

struct input {
    int num_videos;
    int num_endpoints;
    int num_requests;
    int num_caches;
    int caches_size;

    std::vector<cache> caches;
    std::vector<endpoint> endpoints;
    std::vector<int> videos_size;
};

input read_input();


