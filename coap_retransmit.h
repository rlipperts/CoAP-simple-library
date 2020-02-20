//
// Created by i3 on 19.02.20.
//

#ifndef COCOA_COAP_RETRANSMIT_H
#define COCOA_COAP_RETRANSMIT_H

#include "coap-simple.h"

class CoapR {
private:

    Coap coap;
    UDP *_udp;
    CoapUri uri;
    callback resp;
    int _port;

public:
    CoapR(UDP &udp);
    bool start();
    bool start(int port);
    void response(callback c) { resp = c; }

    void server(callback c, String url) { uri.add(c, url); }
    uint16_t sendResponse(IPAddress ip, int port, uint16_t messageid);
    uint16_t sendResponse(IPAddress ip, int port, uint16_t messageid, char *payload);
    uint16_t sendResponse(IPAddress ip, int port, uint16_t messageid, char *payload, int payloadlen);
    uint16_t sendResponse(IPAddress ip, int port, uint16_t messageid, char *payload, int payloadlen, COAP_RESPONSE_CODE code, COAP_CONTENT_TYPE type, uint8_t *token, int tokenlen);

    uint16_t get(IPAddress ip, int port, char *url);
    uint16_t put(IPAddress ip, int port, char *url, char *payload);
    uint16_t put(IPAddress ip, int port, char *url, char *payload, int payloadlen);
    uint16_t send(IPAddress ip, int port, char *url, COAP_TYPE type, COAP_METHOD method, uint8_t *token, uint8_t tokenlen, uint8_t *payload, uint32_t payloadlen);
    uint16_t send(IPAddress ip, int port, char *url, COAP_TYPE type, COAP_METHOD method, uint8_t *token, uint8_t tokenlen, uint8_t *payload, uint32_t payloadlen, COAP_CONTENT_TYPE content_type);

    bool loop();
};

#endif //COCOA_COAP_RETRANSMIT_H
