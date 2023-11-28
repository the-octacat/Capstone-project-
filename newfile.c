#include<stdio.h>

struct Employees {
    char name[50];
    char password[50];
} employee;

struct Booking {
    int busNumber;
    int seatNumber;
    char passengerName[50];
    float payment;
    char bookingtime[10];
    char arrivaltime[10];
    char seatPreference[20]; // Added seat preference,back,front,near a window
} book;

struct Bus {
    int busNumber;
    int totalSeats;
    char source[50];
    char destination[50];
    int availableSeats;
    int bookedSeats;
} customer;

// Function prototype
void chooseSeatPreference();

int main() {
    printf("Employees name: ");
    gets(employee.name);
    printf("Employees password: ");
    gets(employee.password);

    printf("Enter passenger name: ");
    gets(book.passengerName);
    printf("Enter paid amount: ");
    scanf("%f", &book.payment);

    if (book.payment <= 1000) {
        printf("NOT ENOUGH MONEY\n");
        return 1;  // Exiting with an error code
    } else {
        printf("YOU ARE GOOD TO GO\n");
    }

    printf("Enter time of booking: ");
    getchar(); // consume the newline character left in the buffer
    fgets(book.bookingtime, sizeof(book.bookingtime), stdin);
    printf("Enter time of arrival: ");
    fgets(book.arrivaltime, sizeof(book.arrivaltime), stdin);

    printf("Enter Bus number: ");
    scanf("%d", &customer.busNumber);
    printf("Enter total number of seats in the bus: ");
    scanf("%d", &customer.totalSeats);

    // Seat booking
    chooseSeatPreference();

    printf("Enter starting point or source: ");
    getchar(); // consume the newline character left in the buffer
    fgets(customer.source, sizeof(customer.source), stdin);
    printf("Enter destination: ");
    fgets(customer.destination, sizeof(customer.destination), stdin);

    printf("Enter booked seats: ");
    scanf("%d", &customer.bookedSeats);

    // Calculate available seats
    customer.availableSeats = customer.totalSeats - customer.bookedSeats;
    printf("Available seats=%d\n", customer.availableSeats);

    // Display booking details
    printf("\n***** BOOKING PAGE ******\n");
    printf("Employee doing the booking name=%s", employee.name);
    printf("Client's name=%s", book.passengerName);
    printf("Paid amount=%f", book.payment);
    printf("Client's Booking time=%s", book.bookingtime);
    printf("Client's Bus number=%d", customer.busNumber);
    printf("Client's Seat Number=%d", book.seatNumber);
    printf("Client's Seat Preference=%s", book.seatPreference);
    printf("Client is Travelling from:%s To:%s\n", customer.source, customer.destination);

    return 0;
}

void chooseSeatPreference() {
    printf("Choose your seat preference (Front/Back/Window): ");
    fgets(book.seatPreference, sizeof(book.seatPreference), stdin);

    // Implement logic to find a suitable seat based on the preference
    // ...
    }    
