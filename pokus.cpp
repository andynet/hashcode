
/*
bool obsahuje(int video, )


void pridaj(){
	
	for(endpoint e : input.endpoints){
		int cache_pointer = 0;
		
		for(int j = 0; j < e.requests.size(); j++){
			if(	e.l_chache_s[cache_pointer].memory + input.videos_size(e.requests[j].video_id)
				< input.cachces_size){
				if(obsahuje(e.requests[j].video_id, e.l_cache_s[cache_pointer])){
					input.caches[e.l_cache_s[cache_pointer].first].push_back(e.requests[])
				}
			}
		}

	}
}*/


int konst = 1;

bool pomer_comp(pair<double, int> a, pair<double, int> b){
	return a.first > b.first;
}

vector<std::pair<double, int>> zisti_pomery(endpoint &e){
	vector<std::pair<double,int >> res;

	for(int i = 0 ; i < e.requests.size(); i++){
		int video = request[i].video_id;
		int requesty = request[i].count;
		pair pom;
		pom.first = requesty/input.videos_size(video) * konst;
		pom.second = video_id;

		res.push_back(pom);
	}


	sort(res.begin(), res.end(), pomer_comp);

	return res;
}

}

