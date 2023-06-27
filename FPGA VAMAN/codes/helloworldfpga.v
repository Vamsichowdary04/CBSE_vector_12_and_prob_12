/*Program for blinking LED
January 16,2021
Code by G V V Sharma
Released under GNU GPL
*/

//declaring the blink module
module helloworldfpga(
    input wire Q,
    input wire R,
    input wire S,
    output wire led
);
    wire Q_bar;

    assign led = Q & (~R) | S;

endmodule




