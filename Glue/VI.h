//
// Created by Rolf Svenning on 17/04/2023.
//

#ifndef IMPLEMENTATIONS_VI_H
#define IMPLEMENTATIONS_VI_H


class VI {
public:
    VI(int value = -1, int index = -1);
    int v;
    int ind;

    bool operator==(const VI other) const {
        return v == other.v and ind == other.ind;
    }
};


#endif //IMPLEMENTATIONS_VI_H
