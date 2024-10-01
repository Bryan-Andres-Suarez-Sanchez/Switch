package switch;

@license(LGPL);
//
// TODO documentation
//
simple Switch
{
    @display("i=block/classifier2");
    gates:
        input in1;
        input in2;
        input in3;
        input in4;
        output out1;
        output out2;
        output out3;
        output out4;
        
}

//
// TODO documentation
//
simple Terminal1
{
    @display("i=device/switch");
    gates:
        input in;
        output out;
}

//
// TODO documentation
//
simple Terminal2
{
    @display("i=device/switch");
    gates:
        input in;
        output out;
}

//
// TODO documentation
//
simple Terminal3
{
    @display("i=device/switch");
    gates:
        input in;
        output out;
}

//
// TODO documentation
//
simple Terminal4
{
    @display("i=device/switch");
    gates:
        input in;
        output out;
}

//
// TODO documentation
//
network Network
{
    @display("bgb=475,246");
    submodules:
        switch: Switch {
            @display("p=221,112");
        }
        terminal1: Terminal1 {
            @display("p=82,40");
        }
        terminal2: Terminal2 {
            @display("p=374,46");
        }
        terminal3: Terminal3 {
            @display("p=82,191");
        }
        terminal4: Terminal4 {
            @display("p=383,191");
        }
	connections:
        terminal1.out --> switch.in1;
        switch.out1 --> terminal1.in;
        
        terminal2.out --> switch.in2;
        switch.out2 --> terminal2.in;
        
        terminal3.out --> switch.in3;
        switch.out3 --> terminal3.in;
        
        terminal4.out --> switch.in4;
        switch.out4 --> terminal4.in;
}

