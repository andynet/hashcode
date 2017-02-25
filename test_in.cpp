#include <iostream>
#include "load.h"
#include <algorithm>
#include <queue>
#include <unistd.h>
using namespace std;


class ComparePair 
{
    public:
        bool operator()(pair<int,double> a,pair<int,double> b){
            return a.second < b.second;
        }
};



typedef priority_queue<pair<int,double>,vector<pair<int,double>>,ComparePair> my_queue_pomery;

google_input in;



my_queue_pomery zisti_pomery(endpoint &e){
	my_queue_pomery res;
    //cout << "pocet Request: " << e.requests.size() << endl;
	for(int i = 0 ; i < e.requests.size(); i++){
		int video = e.requests[i].video_id;
		int requesty = e.requests[i].count;
		pair<int,double> pom;
		pom.second = ((double) requesty)/(in.videos_size[video]) * (0.2*e.l_data_c);
		pom.first = video;

		res.push(pom);
	}
    //cout << "Vraciam velksot: " << res.size() << endl;
	return res;
}

void print_pomery(vector<pair<int,double>> pomery){
    for(int i =0;i < pomery.size();i++){
        cout << i << "Pomer: " <<  pomery[i].second << endl;
    }
}

bool nachadza(int video,const cache & e){
    for(int i =0; i< e.indexes.size();i++){
        if(e.indexes[i]==video){
            return true;
        }
    }
    return false;
}

bool latency_comp(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}
/*
void priraduj(){
		vector<vector<pair<int,int>> > latencie;

        	for(endpoint e : in.endpoints){
                        vector<pair<int,int>> pom(e.l_cache_s);
        	        sort(pom.begin(), pom.end(), latency_comp);
			latencie.push_back(pom);
		}
                //pomer, video
                vector<vector<pair<int,double>>> pomery2;
		for(endpoint e : in.endpoints){
			pomery2.push_back(zisti_pomery(e));
				
		}


		vector<int> indexy_videa;
		for(int i = 0; i < in.num_endpoints; i++){
			indexy_videa.push_back(0);
		}
	
		bool priradil_som_nieco = true;
		int indxendp = -1;
        long koniec = 0;
		while(!((!priradil_som_nieco) && (indxendp == in.num_endpoints))){
			priradil_som_nieco = false;
            koniec++;
            if(koniec > (in.num_endpoints*in.num_videos*20000))
                break;
			indxendp++;
			if(indxendp == in.num_endpoints) indxendp = 0;
			int i;
                	for(i = indexy_videa[indxendp]; i < pomery2[indxendp].size(); i++){
                        	int cache_index = 0;
                        	while(true){
                                	int index = latencie[indxendp][cache_index].first;
                                	if(nachadza(pomery2[indxendp][i].first, in.caches[index])) { 
                                        priradil_som_nieco = true;
                                        break;
                                    };
                               		if(in.caches[index].memory + in.videos_size[pomery2[indxendp][i].first] <= in.caches_size){
                                        	in.caches[index].memory += in.videos_size[pomery2[indxendp][i].first];
                                            cout << "Zmesti sa" << endl;
                                        	in.caches[index].indexes.push_back(pomery2[indxendp][i].first);
						                    priradil_som_nieco = true;
                                        	break;
                                	} else {
                                        	//Nezmesti sa, Lukáš, ideme skúsiť ďalší cache server
                                        	cache_index++;
                                        	if(cache_index >= latencie[indxendp].size()) break;
                                	}
                        	}
				            if(priradil_som_nieco) break;
                	}
			        indexy_videa[indxendp] = i + 1; 
		}
}
*/


int strcDoKese(endpoint & e,const pair<int,double> & max){
   //rata s tym ze l_cache_s je sortnute
   for(auto c:e.l_cache_s){
        int id = c.first;
        //je v nej miesto?
        //cout << "mesti sa: " << in.videos_size[max.first] << "do velkosti:" << in.caches[id].memory << endl;
        if((in.caches[id].memory + in.videos_size[max.first]) <= in.caches_size){
            //pozret ci tam uz je ?
            if(find(in.caches[id].indexes.begin(),in.caches[id].indexes.end(),max.first)== in.caches[id].indexes.end()){ 
                //nenachadza sa tam
                in.caches[id].memory+=in.videos_size[max.first];
                in.caches[id].indexes.push_back(max.first);
            }
            return 1;
        }  
   }
   return 0;
}

int best_choose(vector<my_queue_pomery> & endp_pomery,pair<int,double> out){
    out.second = 0;
    int i =0;
    for(i=0;i< endp_pomery.size();i++){
        
    }
    return i;
}

void priraduj2(){
    ComparePair comparePair;
    vector<my_queue_pomery> endp_pomery;
    for(auto e: in.endpoints){
        endp_pomery.push_back(zisti_pomery(e));
        sort(e.l_cache_s.begin(),e.l_cache_s.end(),latency_comp);
    }
    //int pridanych = 10;
    int not_empty = in.endpoints.size();
    while(not_empty >0){
        //pridanych = 0;
        not_empty = in.endpoints.size();
        pair<int,double> max;
        int index_pointoch = -1;
        for(int i=0;i < in.endpoints.size();i++){
            if(!endp_pomery[i].empty()){
                pair<int,double> pom= endp_pomery[i].top();
                if(comparePair(max,pom)){
                    max = pom;
                    index_pointoch = i;
                }
                
                //endp_pomery[i].pop();
                //pozrem do ktorej cacshe ho mozem dat
                //pridanych+=strcDoKese(in.endpoints[i],max);
            }
            else{
                not_empty--;
            }
        }
        //cout << "Index_pointov:" << index_pointoch << endl;
        //cout << "Not_empty: " << not_empty << endl;
        //cout << "MAX: " << max.second << endl;
        if(not_empty>0){
            endp_pomery[index_pointoch].pop();
            strcDoKese(in.endpoints[index_pointoch],max);
        }
        
        //cout << "Pridane: " << pridanych << endl;
        //cout << "Endpointov neprazdnych: " << not_empty << endl;
    }

}


int main () {
     in = read_input();
     //print_pomery(pomery); 
     priraduj2();
     cout << in.num_caches << endl;

     for(int i=0;i < in.caches.size();i++){
        cout << i;
        for(int j =0; j< in.caches[i].indexes.size();j++){
            cout << " " << in.caches[i].indexes[j]; 
        }
        cout << endl;

     }

}
