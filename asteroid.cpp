/*
Student ID: 013832065
Name: Sahana Ramesh
Grade ID: 52


Time Complexity: O(n*n)
Space Complexity: O(1)

*/

#include <iostream>
#include <vector>
#include "asteroid.h"

int countHits(std::vector<Asteroid> a){
    int count =0;
    std::vector<Asteroid>::iterator s;

    if(a.empty()){
        std::cerr<<"Vector passed is empty"<<std::endl;
        exit(1);
    }

    for (s = a.begin(); s!=a.end(); s++){
        if (s->m<0){
            std::cerr<<"mass cannot be negative!"<<std::endl;
            exit(1);
        }
    }

    std::vector<Asteroid>::iterator t;
    for (t =a.begin(); t<a.end(); t++){
        std::vector<Asteroid>::iterator i;
        auto j = next(i,0);
        i=a.begin();

        for (j=i+1; j<a.end(); j++){
            if((i->d > j->d)){
                if(i->m >j->m){
                    a.erase(j);
                }else if (i->m <j->m){
                    a.erase(i);
                    i++;
		            t--;
                }else if (i->m ==j->m){
                    a.erase(j);
                    a.erase(i);
                    i++;
                }
            }else{
                i++;
            }
        }
    }
    

    for(int s = 0; s<a.size(); s++){
        if(a.at(s).d>0){
            count++;
        }
    }
	
    return count;
}