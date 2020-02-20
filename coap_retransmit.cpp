//
// Created by i3 on 19.02.20.
//

#include "coap_retransmit.h"
#include <thread>
#include <chrono>

using namespace std;

string text;

void timeout(int millisec) {
    this_thread::sleep_for(chrono::milliseconds(millisec));
    cout << text << endl;
}

int resend() {
    int delay = 10;
    text = "Retransmit, because no ACK received";

    thread t(timeout, delay*1000);

    for (int i = 0; i < delay; ++i) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Seconds passed: " << i + 1 << endl;
    }
    return 0;
}