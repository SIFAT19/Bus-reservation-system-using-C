#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int busnumbers[100]; 
char busRoutes[10][100];
int totalSeats[100];
int availableSeats[100];
float fares[100];
float time[100];


int reservationNumbers[100];
char passengerNames[100][100];
int bookedbusnumbers[100];
int seatNumbers[100];
int numBuses = 0;
int numReservations = 0;

void Dhaka() {
    printf("Available Buses:\n");
    printf("Bus Number\tRoute\t\t\tTotal Seats\tAvailable Seats\t\tFare per Seat\t\t Time\n");
    
    for (int i = 4; i < 8; i++) {  
        printf("%d\t\t%s\t  %d\t\t\t%d\t\t\t%.2f  \t%.2f\n", busnumbers[i], busRoutes[i],
               totalSeats[i], availableSeats[i], fares[i],time[i]);

        
    }
    
}
void khulna() {
    printf("Available Buses:\n");
    printf("Bus Number\tRoute\t\t\tTotal Seats\tAvailable Seats\t\tFare per Seat\t\t Time\n");
    
    for (int i = 8; i < 12; i++) {
        printf("%d\t\t%s\t  %d\t\t\t%d\t\t\t%.2f  \t%.2f\n", busnumbers[i], busRoutes[i],
               totalSeats[i], availableSeats[i], fares[i],time[i]);

        
    }
    
}
void Rangpur() {
    printf("Available Buses:\n");
    printf("Bus Number\tRoute\t\t\tTotal Seats\tAvailable Seats\t\tFare per Seat\t\t Time\n");
    
    for (int i = 12; i < 16; i++) {
        printf("%d\t\t%s\t  %d\t\t\t%d\t\t\t%.2f\t%.2f\n", busnumbers[i], busRoutes[i],
               totalSeats[i], availableSeats[i], fares[i],time[i]);

        
    }
}
void Chattagram() {
    printf("Available Buses:\n");
    printf("Bus Number\tRoute\t\t\tTotal Seats\tAvailable Seats\t\tFare per Seat\t\t Time\n");
    
    for (int i = 16; i < 20; i++) {
        printf("%d\t\t%s\t  %d\t\t\t%d\t\t\t%.2f  \t%.2f\n", busnumbers[i], busRoutes[i],
               totalSeats[i], availableSeats[i], fares[i],time[i]);

        
    }
}
void Rajshahi() {
    printf("Available Buses:\n");
    printf("Bus Number\tRoute\t\t\tTotal Seats\tAvailable Seats\t\tFare per Seat\t\t Time\n");
    
    for (int i = 20; i < 24; i++) {
        printf("%d\t\t%s\t  %d\t\t\t%d\t\t\t%.2f  \t%.2f\n", busnumbers[i], busRoutes[i],
               totalSeats[i], availableSeats[i], fares[i],time[i]);

        
    }
}
void syhlet() {
    printf("Available Buses:\n");
    printf("Bus Number\tRoute\t\t\tTotal Seats\tAvailable Seats\t\tFare per Seat\t\t Time\n");
    
    for (int i = 24; i < 28; i++) {
        printf("%d\t\t%s\t  %d\t\t\t%d\t\t\t%.2f  \t%.2f\n", busnumbers[i], busRoutes[i],
               totalSeats[i], availableSeats[i], fares[i],time[i]);

        
    }
}
void Mymensingh() {
    printf("Available Buses:\n");
    printf("Bus Number\tRoute\t\t\tTotal Seats\tAvailable Seats\t\tFare per Seat\t\t Time\n");
    
    for (int i = 28; i < 32; i++) {
        printf("%d\t\t%s\t  %d\t\t\t%d\t\t\t%.2f  \t%.2f\n", busnumbers[i], busRoutes[i],
               totalSeats[i], availableSeats[i], fares[i],time[i]);

        
    }
}


void Outerdivdisplay() {
    printf("Available Buses:\n");
    printf("Bus Number\tRoute\t\t\tTotal Seats\tAvailable Seats\t\tFare per Seat\t\t Time\n");
    
    for (int i = 0; i < 4; i++) {
        printf("%d\t\t%s\t  %d\t\t\t%d\t\t\t%.2f  \t%.2f\n", busnumbers[i], busRoutes[i],
               totalSeats[i], availableSeats[i], fares[i],time[i]);
    }
}

void interdivdisplay() {
    printf("Available Buses:\n");
    printf("Bus Number\tRoute\t\t\tTotal Seats\tAvailable Seats\t\tFare per Seat\t\t Time\n");
    
    for (int i = 4; i < numBuses; i++) {
        printf("%d\t\t%s\t  %d\t\t\t%d\t\t\t%.2f\n", busnumbers[i], busRoutes[i],
               totalSeats[i], availableSeats[i], fares[i],time[i]);
    }
}



// Function to book a reservation
void bookReservation() {
    int busNumber, seatNumber;
    char passengerName[100];
    
    printf("Enter Passenger Name: ");
    scanf("%s", passengerName);
    fflush(stdin);
    printf("Enter Bus Number: ");
    scanf("%d", &busNumber);
    

    int busIndex = -1;
    for (int i = 0; i < numBuses; i++) {
        if (busnumbers[i] == busNumber) {
            busIndex = i;
            break;
        }
    }
    
    if (busIndex == -1) {
        printf("Bus with the given number not found.\n");
        return;
    }
    
    if (availableSeats[busIndex] == 0) {
        printf("No available seats on this bus.\n");
        return;
    }
    
    printf("Enter Seat Number: ");
    scanf("%d", &seatNumber);
    
    if (seatNumber < 1 || seatNumber > totalSeats[busIndex]) {
        printf("Invalid seat number.\n");
        return;
    }
    

    availableSeats[busIndex]--;
    reservationNumbers[numReservations] = numReservations + 1;
    strcpy(passengerNames[numReservations], passengerName);
    bookedbusnumbers[numReservations] = busNumber;
    seatNumbers[numReservations] = seatNumber;
    numReservations++;
    
    printf("Reservation successful!\n");
}

// Function to display reservations
void displayReservations() {
    printf("Reservations:\n");
    printf("Reservation Number\tPassenger Name\tBus Number\tSeat Number\n");
    
    for (int i = 0; i < numReservations; i++) {
        printf("%d\t\t\t%s\t\t%d\t\t%d\n", reservationNumbers[i],
               passengerNames[i], bookedbusnumbers[i], seatNumbers[i]);
    }
}


int main() {
    // buses with data
    busnumbers[numBuses] = 1;
    strcpy(busRoutes[numBuses], "Route Dhaka To Khulna");
    totalSeats[numBuses] = 36;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 650;
    time[numBuses]=10.20 ;
    numBuses++;
    
    busnumbers[numBuses] = 2;
    strcpy(busRoutes[numBuses], "Route Dhaka to Barishal");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 40;
    fares[numBuses] = 700;
    time[numBuses]=12.20;
    numBuses++;

    busnumbers[numBuses] = 3;
    strcpy(busRoutes[numBuses], "Route Dhaka To Cumilla");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 450;
    time[numBuses]=01.40;
    numBuses++;

    busnumbers[numBuses] = 4;
    strcpy(busRoutes[numBuses], "Route Dhaka To shylet");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 30;
    fares[numBuses] = 1050;
    time[numBuses]=11.20;
    numBuses++;

    busnumbers[numBuses] = 5;
    strcpy(busRoutes[numBuses], "Dhaka city To Gazipur");
    totalSeats[numBuses] = 36;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 120;
    time[numBuses]=10.20 ;
    numBuses++;
    
    busnumbers[numBuses] = 6;
    strcpy(busRoutes[numBuses], "Dhaka to Norshingdi");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 40;
    fares[numBuses] = 200;
    time[numBuses]=8.00;
    numBuses++;

    busnumbers[numBuses] = 7;
    strcpy(busRoutes[numBuses], "Dhaka To Narayanganj");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 150;
    time[numBuses]=4.00 ;
    numBuses++;

     busnumbers[numBuses] = 8;
    strcpy(busRoutes[numBuses], "Dhaka city To Savar");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 100;
    time[numBuses]=10.20;
    numBuses++;

     busnumbers[numBuses] = 9;
    strcpy(busRoutes[numBuses], "Khulna to Jessore");
    totalSeats[numBuses] = 36;
    availableSeats[numBuses] = 10;
    fares[numBuses] = 120;
    time[numBuses]=12.40 ;
    numBuses++;
    
     busnumbers[numBuses] = 10;
    strcpy(busRoutes[numBuses], "Khulna to Satkhira");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 40;
    fares[numBuses] = 200;
    time[numBuses]=8.00;
    numBuses++;

     busnumbers[numBuses] = 11;
    strcpy(busRoutes[numBuses], "Khulna To Bagerhat");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 150;
    time[numBuses]=10.20;
    numBuses++;

     busnumbers[numBuses] = 12;
    strcpy(busRoutes[numBuses], "Khulna To Norail");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 100;
    time[numBuses]=3.15 ;
    numBuses++;

     busnumbers[numBuses] = 13;
    strcpy(busRoutes[numBuses], "Rangpur to Dinajpur");
    totalSeats[numBuses] = 36;
    availableSeats[numBuses] = 10;
    fares[numBuses] = 120;
    time[numBuses]=8.00;
    numBuses++;
    
     busnumbers[numBuses] = 14;
    strcpy(busRoutes[numBuses], "Rangpur to Kurigram ");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 40;
    fares[numBuses] = 130;
    time[numBuses]=10.20 ;
    numBuses++;

     busnumbers[numBuses] = 15;
    strcpy(busRoutes[numBuses], "Rangpur To Gaibandha");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 120;
    time[numBuses]=3.15;
    numBuses++;

     busnumbers[numBuses] = 16;
    strcpy(busRoutes[numBuses], "Rangpur To Thakurgaon");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 100;
    time[numBuses]=7.30;
    numBuses++;
    busnumbers[numBuses] = 17;
    strcpy(busRoutes[numBuses], "Chattagram to Cox's Bazar");
    totalSeats[numBuses] = 36;
    availableSeats[numBuses] = 10;
    fares[numBuses] = 120;
    time[numBuses]=10.20;
    numBuses++;
    
    busnumbers[numBuses] = 18;
    strcpy(busRoutes[numBuses], "Chattagram to Bandarban ");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 40;
    fares[numBuses] = 130;
    time[numBuses]=3.15 ;
    numBuses++;

    busnumbers[numBuses] = 19;
    strcpy(busRoutes[numBuses], "Chattagram To   Rangamati");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 120;
    time[numBuses]=5.30;
    numBuses++;

     busnumbers[numBuses] = 20;
    strcpy(busRoutes[numBuses], "Chattagram To Khagrachori");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 100;
    time[numBuses]=10.20;
    numBuses++;

    busnumbers[numBuses] = 21;
    strcpy(busRoutes[numBuses], "Rajshahi to Natore");
    totalSeats[numBuses] = 36;
    availableSeats[numBuses] = 10;
    fares[numBuses] = 120;
    time[numBuses]=6.00;
    numBuses++;
    
    busnumbers[numBuses] = 22;
    strcpy(busRoutes[numBuses], "Rajshahi to Pabna");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 40;
    fares[numBuses] = 130;
    time[numBuses]=5.30 ;
    numBuses++;

    busnumbers[numBuses] = 23;
    strcpy(busRoutes[numBuses], "Rajshahi To Bogura");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 120;
    time[numBuses]=10.20;
    numBuses++;

    busnumbers[numBuses] = 24;
    strcpy(busRoutes[numBuses], "Rajshahi To Joypurhat");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 100;
    time[numBuses]=7.30 ;
    numBuses++;    

    busnumbers[numBuses] = 25;
    strcpy(busRoutes[numBuses], "Sylhet to Habiganj");
    totalSeats[numBuses] = 36;
    availableSeats[numBuses] = 10;
    fares[numBuses] = 120;
    time[numBuses]=5.30;
    numBuses++;
    
    busnumbers[numBuses] = 26;
    strcpy(busRoutes[numBuses], "Sylhet to Moulvibazar");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 40;
    fares[numBuses] = 130;
    time[numBuses]=3.30;
    numBuses++;

    busnumbers[numBuses] = 27;
    strcpy(busRoutes[numBuses], "Sylhet To Sunamganj");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 120;
    time[numBuses]=5.30;
    numBuses++;

    busnumbers[numBuses] = 28;
    strcpy(busRoutes[numBuses], "Sylhet To Srimongal");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 100;
    time[numBuses]=11.00;
    numBuses++;

     busnumbers[numBuses] = 29;
    strcpy(busRoutes[numBuses], "Mymensingh to Kishoreganj");
    totalSeats[numBuses] = 36;
    availableSeats[numBuses] = 10;
    fares[numBuses] = 120;
    time[numBuses]=5.30;
    numBuses++;
    
    busnumbers[numBuses] = 30;
    strcpy(busRoutes[numBuses], "Mymensingh to Tangail");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 40;
    fares[numBuses] = 130;
    time[numBuses]=7.30;
    numBuses++;

    busnumbers[numBuses] = 31;
    strcpy(busRoutes[numBuses], "Mymensingh to Sherpur");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 120;
    time[numBuses]=6.30;
    numBuses++;

    busnumbers[numBuses] = 32;
    strcpy(busRoutes[numBuses], "Mymensingh to Jamalpur");
    totalSeats[numBuses] = 40;
    availableSeats[numBuses] = 20;
    fares[numBuses] = 100;
    time[numBuses]=10.20;
    numBuses++;


    
    int choice;
    
    while (1) {
        printf("\nBus Reservation System\n");
        printf("1. Display Available Buses\n");
        printf("2. Book Reservation\n");
        printf("3. Display Reservations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:{
            int temp;
                printf("Choose one of the following\n ");
                printf("1.Inter division\n 2.Outer division\n");
                printf("Enter Your choise:");
                scanf("%d",&temp);
                switch (temp)
                {
                    
                case 1:{
                    int temp1;
                    printf("Choose your Division:\n");
                    printf("1.Dhaka\n2.Khulna\n3.Rangpur\n4.Chattogram\n5.Rajshahi\n6.Sylhet\n7.Mymensingh\n");
                    scanf("%d",&temp1);
                    switch (temp1)
                    {
                    case 1:
                        Dhaka();

                        break;

                    case 2:
                        khulna();
                        
                        break;
                    case 3:
                        Rangpur();
                        break;
                    case 4:
                        Chattagram();
                        break;
                
                    case 5:
                        Rajshahi();
                        break;
                    case 6:
                        syhlet();
                        break;
                    case 7:
                        Mymensingh();
                        break;
                    }
                    
                    break;
                }
                case 2:
                    Outerdivdisplay();
                     break;


                default:
                    break;
                }
                
                break;
            }
            case 2:
                bookReservation();
                break;
                
            case 3:
                displayReservations();
                break;
                
            case 4:
                printf("Exiting program.\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
