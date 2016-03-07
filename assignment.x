struct inData {
	int mode;
        char user[256];
        char pass[256];
};

struct outData {
	int rCode;
        char rString[256];
};

program ADD_PROG {
        version ADD_VERS {
                outData REGISTER(inData) = 1;
                outData LOGIN(inData) = 2;
        } = 1;
} = 0x33451111;
