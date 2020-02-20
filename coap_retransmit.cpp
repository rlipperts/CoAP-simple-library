//
// Created by i3 on 19.02.20.
//

#include "coap_retransmit.h"
#include <thread>
#include <chrono>
#include <iostream>


std::string text;

//--------------------------------------------------------------------------------------------------------------------//
//                    Additional functions                                                                            //
//--------------------------------------------------------------------------------------------------------------------//

void timeout(int millisec) {
    std::this_thread::sleep_for(std::chrono::milliseconds(millisec));
    std::cout << text << std::endl;
}

int resend() {
    int delay = 10;
    text = "Retransmit, because no ACK received";

    std::thread t(timeout, delay*1000);

    for (int i = 0; i < delay; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Seconds passed: " << i + 1 << std::endl;
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------------------//
//                    Wrapped functions                                                                               //
//--------------------------------------------------------------------------------------------------------------------//

// basic functions

CoapR::CoapR(UDP &udp): coap(udp) {
    coap = Coap(udp);
}

bool CoapR::start() {
    return coap.start();
}

bool CoapR::start(int port) {
    return coap.start(port);
}

// response functions

uint16_t CoapR::sendResponse(IPAddress ip, int port, uint16_t messageid) {
    return coap.sendResponse(ip, port, messageid);
}

uint16_t CoapR::sendResponse(IPAddress ip, int port, uint16_t messageid, char *payload) {
    return coap.sendResponse(ip, port, messageid, payload);
}

uint16_t CoapR::sendResponse(IPAddress ip, int port, uint16_t messageid, char *payload, int payloadlen) {
    return coap.sendResponse(ip, port, messageid, payload, payloadlen);
}

uint16_t
CoapR::sendResponse(IPAddress ip, int port, uint16_t messageid, char *payload, int payloadlen, COAP_RESPONSE_CODE code,
                    COAP_CONTENT_TYPE type, uint8_t *token, int tokenlen) {
    return coap.sendResponse(ip, port, messageid, payload, payloadlen, code, type, token, tokenlen);
}

// client request functions
//todo: when sending a CON packet, put packet into retransmission thingie

uint16_t CoapR::get(IPAddress ip, int port, char *url) {
    return coap.get(ip, port, url);
}

uint16_t CoapR::put(IPAddress ip, int port, char *url, char *payload) {
    return coap.put(ip, port, url, payload);
}

uint16_t CoapR::put(IPAddress ip, int port, char *url, char *payload, int payloadlen) {
    return coap.put(ip, port, url, payload, payloadlen);
}

uint16_t
CoapR::send(IPAddress ip, int port, char *url, COAP_TYPE type, COAP_METHOD method, uint8_t *token, uint8_t tokenlen,
            uint8_t *payload, uint32_t payloadlen) {
    return coap.send(ip, port, url, type, method, token, tokenlen, payload, payloadlen);
}

uint16_t
CoapR::send(IPAddress ip, int port, char *url, COAP_TYPE type, COAP_METHOD method, uint8_t *token, uint8_t tokenlen,
            uint8_t *payload, uint32_t payloadlen, COAP_CONTENT_TYPE content_type) {
    return coap.send(ip, port, url, type, method, token, tokenlen, payload, payloadlen, content_type);
}

bool CoapR::loop() {
    return coap.loop();
}
