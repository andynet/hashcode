#include "load.h"
using namespace std;

input read_input(){
    input in;
    //prvy riadok
    cin >> in.num_videos;
    cin >> in.num_endpoints;
    cin >> in.num_requests;
    cin >> in.num_caches;
    cin >> in.caches_size;
    
    


    for(int i =0;i < in.num_caches;i++){
        cache pom;
        pom.memory = 0;
        in.caches.push_back(pom);
    }
    //cout << "[*] cache nacitane" << endl;
    for(int i =0;i < in.num_videos;i++){
        int pom;
        cin >> pom;
        in.videos_size.push_back(pom);
    }
    //cout << "[*] Videa nacitane" << endl;
    
    for(int i = 0; i < in.num_endpoints;i++){
        endpoint pom;
        cin >> pom.l_data_c;
        cin >> pom.connections;
        for(int j =0; j < pom.connections;j++){
            pair<int,int> pom2;
            cin >> pom2.first;
            cin >> pom2.second;
            pom.l_cache_s.push_back(pom2);
        }
        in.endpoints.push_back(pom);
    }
    //cout << "[*] Endpoint nacitane" << endl;
    for(int i =0; i< in.num_requests;i++){
       request pom;
       cin >> pom.video_id;
       int endpoint_id;
       cin >> endpoint_id;
       cin >> pom.count;
       in.endpoints[endpoint_id].requests.push_back(pom);
    }
    //cout << "[*] County nacitane" << endl;


    return in;
}

