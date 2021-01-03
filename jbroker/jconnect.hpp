#include <assert.h>

#include "broker/broker.hh"
#include "broker/zeek.hh"

using namespace broker;

/*int main() {
    // Setup endpoint and connect to Zeek.
    endpoint ep;
    auto sub = ep.make_subscriber({"/topic/test"});
    auto ss = ep.make_status_subscriber(true);
    ep.peer("127.0.0.1", 9999);

    // Wait until connection is established.
    auto ss_res = ss.get();
    auto st = caf::get_if<status>(&ss_res);
    if ( ! (st && st->code() == sc::peer_added) ) {
        std::cerr << "could not connect" << std::endl;
        return 1;
    }

    for ( int n = 0; n < 5; n++ ) {
        // Send event "ping(n)".
        zeek::Event ping("ping", {n});
        ep.publish("/topic/test", ping);

        // Wait for "pong" reply event.
        auto msg = sub.get();
        zeek::Event pong(move_data(msg));
        std::cout << "received " << pong.name() << pong.args() << std::endl;
    }

    return 0;
}*/



class JData {
public:
  data data_;
/*
  JData(int arg) {
    data_ = data(arg);
    print();
  }

  JData(std::string arg);

  JData(bool arg) {
    data_ = data(arg);
  }*/

/*
  JData(int args[], int size) {
    std::vector<data> data_list(size);
    for (int i=0; i<size; ++i) {
      data_list[i]= data(args[i]);
    }
    data_ = data(data_list);
    print();
  }*/

  JData() {}

  JData(std::string arg);

  JData(std::vector<std::string> args);

  void print();

};


class JEndpoint {
public:
  endpoint ep;

  void peer(std::string ip, int port);

  void publish(std::string channel, std::string event_name, std::vector<JData> args);

  void test();

};
