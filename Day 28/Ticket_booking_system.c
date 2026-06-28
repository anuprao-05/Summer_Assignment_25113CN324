#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 20
#define MAX 100

struct Ticket {
    int ticketId;
    char name[50];
    int seatNo;
};

int main() {
    struct Ticket tickets[MAX];
    int seatStatus[TOTAL_SEATS + 1] = {0};   // 0 = empty, 1 = booked
    int n = 0, nextTicketId = 1;
    int choice, i, j, ticketId, found, seat, availableCount;

    do {
        printf("\n========================================\n");
        printf("   TICKET BOOKING SYSTEM\n");
        printf("========================================\n");
        printf("1. Book Ticket\n");
        printf("2. Display All Bookings\n");
        printf("3. Cancel Ticket\n");
        printf("4. Check Seat Availability\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Find first available seat
            seat = -1;
            for (i = 1; i <= TOTAL_SEATS; i++) {
                if (seatStatus[i] == 0) {
                    seat = i;
                    break;
                }
            }

            if (seat == -1) {
                printf("\nSorry! No seats available.\n");
            } else {
                printf("\nEnter Passenger Name : ");
                scanf(" %[^\n]", tickets[n].name);

                tickets[n].ticketId = nextTicketId;
                tickets[n].seatNo   = seat;
                seatStatus[seat]    = 1;

                printf("\nTicket booked successfully!\n");
                printf("Ticket ID : %d\n", tickets[n].ticketId);
                printf("Seat No   : %d\n", tickets[n].seatNo);

                nextTicketId++;
                n++;
            }
        }

        else if (choice == 2) {
            if (n == 0) {
                printf("\nNo bookings found.\n");
            } else {
                printf("\n%-12s %-20s %-10s\n", "Ticket ID", "Name", "Seat No");
                printf("------------------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%-12d %-20s %-10d\n", tickets[i].ticketId, tickets[i].name, tickets[i].seatNo);
                }
            }
        }

        else if (choice == 3) {
            printf("\nEnter Ticket ID to cancel : ");
            scanf("%d", &ticketId);
            found = 0;
            for (i = 0; i < n; i++) {
                if (tickets[i].ticketId == ticketId) {
                    seatStatus[tickets[i].seatNo] = 0;   // free the seat

                    for (j = i; j < n - 1; j++) {
                        tickets[j] = tickets[j + 1];
                    }
                    n--;
                    printf("\nTicket cancelled successfully!\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("\nTicket ID %d not found.\n", ticketId);
        }

        else if (choice == 4) {
            availableCount = 0;
            for (i = 1; i <= TOTAL_SEATS; i++) {
                if (seatStatus[i] == 0)
                    availableCount++;
            }

            printf("\nTotal Seats     = %d\n", TOTAL_SEATS);
            printf("Booked Seats    = %d\n", TOTAL_SEATS - availableCount);
            printf("Available Seats = %d\n", availableCount);

            printf("\nAvailable Seat Numbers : ");
            for (i = 1; i <= TOTAL_SEATS; i++) {
                if (seatStatus[i] == 0)
                    printf("%d ", i);
            }
            printf("\n");
        }

        else if (choice == 5) {
            printf("\nExiting program. Goodbye!\n");
        }

        else {
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}