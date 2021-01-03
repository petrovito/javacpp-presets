
#include "jconnect.hpp"

using namespace broker;


  JData::JData(std::vector<std::string> args) {
      int size = args.size();
      std::vector<data> data_list(size);
      for (int i=0; i<size; ++i) {
        data_list[i]= data(args[i]);
      }
      data_ = data(data_list);
      std::cout << data_ << std::endl;
    }

  JData::JData(std::string arg) {
    data_ = data(arg);
    //std::cout <<data_ << std::endl;
  }

  void JData::print() {
    std::cout <<data_ << std::endl;
  }


  void JEndpoint::peer(std::string ip, int port) {
    ep.peer(ip, port);
  }

  void JEndpoint::publish(std::string channel, std::string event_name, std::vector<JData> args) {
    std::vector<data> data_list(args.size());
    for (int i=0; i<args.size(); ++i) {
      data_list[i]=args[i].data_;
      //std::cout << data_list[i] << std::endl;
    }
    //broker::set s;
    zeek::Event event(event_name, data_list);
    //zeek::Event even2t(event_name, {1,2,"asd", s, data_list});

    std::cout << channel << event_name << data_list << std::endl;
    ep.publish(channel, event);
  }

  void JEndpoint::test() {
      peer("127.0.0.1", 47761);
      JData jd1("atestsd");
      JData jd2("asdfew");
      //zeek::Event event("infoo", {"as", "sd"});
      //std::vector<data> data_list = {"asssss", "sd"};
      std::vector<JData> data_list = {jd1, jd2};
      //std::cout << "asd" << "event_name"<< std::endl;
      publish("/topic/test", "infoo", data_list);
  }
