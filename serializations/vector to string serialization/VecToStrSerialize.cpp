#include <string>
#include <vector>
#include <sstream>
#include <iostream>

std::vector<std::string> deserialize_array(std::string const &csv)
{
  std::istringstream parse(csv);
  std::vector<std::string> ret;
  for(std::string token; std::getline(parse, token, ','); ret.push_back(token));
  return ret;
}

std::string serialize_array(std::string* array_ptr, std::size_t N)
{
  std::ostringstream cat;
  for(std::size_t index= 0; index< N; ++ index)
    cat<< array_ptr[index]<< ',';
  std::string ret= cat.str();
  return ret.substr(0, ret.size()-1);
}

int main()
{
  std::string data= "1,2,3";
  std::cout<< "Data: "<< data<< std::endl;
  std::vector<std::string> deserialized= deserialize_array(data);
  std::string serialized= serialize_array(deserialized.data(), deserialized.size());
  std::cout<< "Serialized + Deserialized: "<< serialized<< std::endl;
}