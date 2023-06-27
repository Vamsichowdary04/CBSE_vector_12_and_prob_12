
module helloworldfpga(
    input wire Q,
    input wire R,
    input wire S,
    output wire led
);
    wire Q_bar;

    assign led = Q & (~R) | S;

endmodule




