#include "random.hpp"

int main(){
	std::vector<int> vec = random_gen<int> (100);
	for (auto i : vec){
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
