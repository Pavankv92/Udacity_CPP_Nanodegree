#include<iostream>
#include<fstream>
#include<string>

#include<dirent.h>
//#include<unistd.h>
#include<regex>
using std::string ;
using std::cout ;

const std::string file_path{"pavan.txt"};
const std::string MemPath{"/proc/2221/status"} ;
const std::string kOSPath{"/etc/os-release"} ;

void ReadTxtFile(std::string path){
	std::ifstream file(path);
	if (file.is_open()) {
		string line ;	
		while (getline(file, line)) {
		cout << line << "\n";
		}
	}
}

float ReadInternalKernalFile(std::string path){
	std::string key, value, line, size ;
	float MemTotal= 0.0, MemFree = 0.0;
	std::ifstream file(path);
	if (file.is_open()) {
		
		int lineNumber = 1 ;
		while (getline(file, line)) {
			std::replace(line.begin(), line.end(), ':', ' ');
			std::istringstream linestream(line) ;
			while (linestream >> key >>  value >> size ) {
				if (key == "MemTotal") {MemTotal = std::stof(value) ;}
				if (key == "MemFree") {MemFree = std::stof(value) ; }
				//cout << "Key: " << " "<<key << "value: " << " "<< value << "size: " << size << "\n" ;
				//cout<< "Memory : " << (MemTotal - MemFree) / MemTotal << "\n" ;
			}
			
				}
			}
		return (MemTotal - MemFree) / MemTotal ;
		
		}
	
std::string OperatingSystem(std::string kOSPath) {
	std::string key, value, size,line, ram_util;
  	std::ifstream stream(kOSPath);
  	if (stream.is_open()){
    	while(std::getline(stream, line)){
      	std::replace(line.begin(), line.end(), ':', ' ');
		//std::cout << line ;
			std::istringstream linestream(line) ;
			while(linestream >> key >> value >> size){
				if (key == "Uid") {
					ram_util = value;
				return ram_util ; }
		  		}
		}
  	}
  	return std::string(); }

std::vector<string> CpuUtilization(std::string kOSPath) {
	std::string key, line ;
	std::ifstream stream(kOSPath);
	std::vector<std::string> list;
	int count = 0;
  	if (stream.is_open()){
    	std::getline(stream, line);
		cout << line << "\n";
		std::istringstream linestream(line) ;
		while (linestream >> key) {
			//cout << key << "\n" ;
			if (key != "cpu"){
				list.push_back(key) ;
			}
		}
  	}
  	return list; 
}

long ActiveJiffies(std::string kOSPath) { 
  auto list = CpuUtilization(kOSPath);
  long sum = 0;
  for (int i = 0; i< list.size(); i++) {
    if (i == 3 || i == 4){sum += std::stof(list[i]);}
  }
  return sum; 
}

long activeJiffies(std::string kOSPath) {
	std::string key, line ;
	std::ifstream stream(kOSPath);
	std::vector<std::string> list;
	long total_time, utime, stime, cutime, cstime;
  	if (stream.is_open()){
    	std::getline(stream, line);
		cout << line << "\n";
		std::istringstream linestream(line) ;
		while (linestream >> key) {
			list.push_back(key) ;
		}
  	}
	utime = std::stof(list[13]);
	stime = std::stof(list[14]);
	cutime = std::stof(list[15]);
	cstime = std::stof(list[16]);
	total_time = utime + stime + cutime + cstime;
	return total_time ;
}


int main(){
	// to access any text file 
	//ReadTxtFile(file_path) ;
	// to acess any 
	//auto mem = OperatingSystem(MemPath) ;
	auto mem = activeJiffies("/proc/2221/stat") ;
	cout << mem  ;
	//OperatingSystem(kOSPath);

return 0;
}



