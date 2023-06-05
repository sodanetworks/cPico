#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "lwip/tcp.h"

// Function to get the internal temperature of Raspberry Pi Pico W
float get_internal_temperature() {
    // Code to read the internal temperature sensor on Raspberry Pi Pico W
    // Implement this function according to the specifications of your hardware.
    // Return the temperature value as a float.
    // You can use the pico-sdk to access the internal temperature sensor.

    // For example, if you have implemented a function to read the temperature
    // and store it in a variable called "temperature", you can use the following code:
    // return temperature;

    // Placeholder return statement
    return 1.1f;
}

// Callback function for handling incoming TCP connections
err_t accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err) {
    // Set up the receive callback function
    tcp_recv(newpcb, [](void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {
        if (p != NULL) {
            // Handle received data if needed
            pbuf_free(p);
        }
    });

    // Set up the sent callback function
    tcp_sent(newpcb, [](void *arg, struct tcp_pcb *tpcb, u16_t len) {
        // TCP data has been successfully sent
    });

    // Continuously send the internal temperature to the client in a loop
    while (true) {
        float temperature = get_internal_temperature();
        char temperature_str[10];
        sprintf(temperature_str, "%.2f", temperature);
        tcp_write(newpcb, temperature_str, strlen(temperature_str), TCP_WRITE_FLAG_COPY);

        // Delay between consecutive temperature updates (in milliseconds)
        const uint32_t update_delay_ms = 1000;
        sleep_ms(update_delay_ms);
    }

    // Close the connection
    tcp_close(newpcb);
    return ERR_OK;
}

int main() {
    // Initialize the Raspberry Pi Pico SDK
    stdio_init_all();

    // Initialize the lwIP TCP/IP stack
    tcpip_init(NULL, NULL);

    // Create a new TCP PCB (Protocol Control Block) structure
    struct tcp_pcb *pcb = tcp_new();

    // Bind the PCB to a specific IP address and port
    ip_addr_t local_ip;
    IP_ADDR4(&local_ip, 192, 168, 100, 56); // Change this to your desired local IP address
    tcp_bind(pcb, &local_ip, 4242);         // Change this to your desired local port number

    // Set up the callback function for incoming connections
    tcp_listen(pcb);
    tcp_accept(pcb, accept_callback);

    // Main loop
    while (true) {
        // Handle lwIP periodic tasks (e.g., timeouts, retransmissions)
        tcp_tmr();
    }

    return 0;
}
