#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define safetypin 1234
#define MAX_LENGTH 100

struct Login{
	char username[10];
	char password[10];
};

typedef struct {
    int id;
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    char status[MAX_LENGTH];
    char timedate[MAX_LENGTH];
} Book;

typedef struct {
    int id;
    char name[MAX_LENGTH];
    int year;
} Student;

void bookshelf();
void Title();
void pressAnyKeyToContinue();
void loader();

void mainmenu();

void login();
void wrongusername();
void wrongpassword();

void adminportal();
void registerbook(Book book);
void updateBookDetails(int bookId, const char* field, const char* newValue);
void listBorrowed();
void listReturned();
void availablebooks();

void studentportal();
void updateStudentDetails(int studentId, const char* field, const char* newValue);
void askstudent(Student *student);
void registerstudent();
void borrowbook(int bookID, const char *studentID);
void displayBorrowedBooks(const char *studentID);
void returnbook(const char *studentID, int bookID);

int main() {
	
	pressAnyKeyToContinue();
	mainmenu();

    return 0;
}

void bookshelf(){
	sleep(1);
	system("cls");
	printf("\n\t\t\t\t\t       .--.           .---.        .-.\n");
	printf("\t\t\t\t\t   .---|--|   .-.     |   |  .-.-. |~|    .--.\n");
	printf("\t\t\t\t\t.-.|===|  |---|_|--.__|   |--|:::| |~|-==-|==|---.\n");
	printf("\t\t\t\t\t|  |   |  |===| |~~|  |   |--|   |_|~|    |  |___|-.\n");
	printf("\t\t\t\t\t|  |   |  |===| |==|  |   |  |:::|=| |    |  |---|=|\n");
	printf("\t\t\t\t\t|  |   |  |   |_|__|  |   |__|   | | |    |  |   | |\n");
	printf("\t\t\t\t\t|~~|===|--|===|~|~~|  |~~~|--|:::|=|~|----|==|---|=|\n");
	printf("\t\t\t\t\t'..^...^..^...^.^..^..^...^..^...^.^.^.==.^..^...^.'\n");
}

void Title(){
	printf("\t _    _ _                        __  __                                       _     ___         _\n");
	printf("\t| |  (_) |__ _ _ __ _ _ _ _  _  |  \\/  |__ _ _ _  __ _ __ _ ___ _ __  ___ _ _| |_  / __|_  _ __| |_ ___ _ __\n");
	printf("\t| |__| | `_ \\ `_/ _` | `_| || | | |\\/| / _` | ` \\/ _`\\/ _` / -_) `  \\/ -_) ` \\  _| \\__ \\ || (_-<  _/ -_) `  \\\n");
	printf("\t|____|_|_,__/_| \\__,_|_|  \\_, | |_|  |_\\__,_|_||_\\__,_\\__, \\___|_|_|_\\___|_||_\\__| |___/\\_, /__/\\__\\___\\_|_|_|\n");
	printf("\t                          |__/                        |___/                             |__/\n");
}

void pressAnyKeyToContinue() {
	bookshelf();
	Title();
    printf("\n\n\n\n%75s", "Press ENTER to continue...");
    getchar();
    
    loader();
}

void loader(){
	int i = 0;
	int counter = 0;
	
	while(i != 4){
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n%65s %d%%\n", "Loading...", counter);
		counter += 33;
		printf("\n\t\t\t");
		if(i == 1){
			printf("[][][][][][][][][][][][][]");
		}
		if(i == 2){
			printf("[][][][][][][][][][][][][][][][][][][][][][][][][][]");
		}
		if(i == 3){
			printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]");
		}
		i++;
		sleep(1);
	}
}

void mainmenu(){
	struct Login validate;
	int choice = 0;
	
	while(choice != 3){
		system("cls");
		
		bookshelf();
		printf("\n\t\t\tMAIN MENU\n");
		printf("\t\t\t[1] Admin Login\n");
		printf("\t\t\t[2] Student Portal\n");
		printf("\t\t\t[3] Exit\n\n");
		
		printf("\t\t\tChoice: ");
		scanf(" %d", &choice);
		
		switch(choice){
			case 1:
				login();
				break;
			case 2:
				studentportal();
				break;
			case 3:
				printf("\t\t\tExiting... Thank you!...");
				exit(0);
				break;
			default:
				printf("\t\t\tNot in the options!");
				break;
		}
	}
}

void login(){
	struct Login validate;
	printf("\n\t\t\t(i)Hint: Enter \"cancel\" to cancel login");
	printf("\n\n\t\t\tEnter Username: ");
	scanf("%10s", validate.username); // Read up to 10 characters to avoid buffer overflow
	getchar(); // Consume newline character left in the input buffer
	
	char cancel[6];
	if(strcmpi(validate.username, "cancel") == 0){
		printf("\n\t\t\tAre you sure to cancel login? [y/n]: ");
		scanf(" %6s", &cancel);
		getchar();
		
		if(strcmpi(cancel, "y") == 0){
			printf("\n\t\t\tGoing back to Main Menu...");
			mainmenu();
		}
		
		if(strcmpi(cancel, "n") == 0){
			login();
		}
		
		else {
			printf("\n\t\t\tNot in the options!");
		}
		
	}
	
	if(strcmpi(validate.username, "admin") == 0){
		printf("\t\t\tEnter Password: ");
		scanf("%10s", validate.password); // Read up to 10 characters to avoid buffer overflow
		getchar(); // Consume newline character left in the input buffer
		
		if(strcmpi(validate.password, "admin") == 0){
			adminportal();
		}
		if(strcmpi(validate.password, "admin") != 0){
			wrongpassword();
		}
	}
	
	if(strcmpi(validate.username, "admin") != 0){
		wrongusername();
	}
	
}

void wrongusername(){
	int pin;
	int choice = 0;
	char cancel;
	
    printf("\n\n\t\t\tIncorrect Username!\n\n");
    printf("\t\t\t[1] Re-enter Username\n");
    printf("\t\t\t[2] Enter Safety Pin\n");
    printf("\t\t\t[3] Cancel Login (Back to Main Menu)\n\n");
    
    printf("\t\t\tChoice: ");
    scanf("%d", &choice);
    
    switch(choice){
    	case 1:
    		login();
    		break;
    	case 2:
    		printf("\n\n\t\t\tEnter Safety Pin: ");
    		scanf("%d", &pin);
    		
    		if(pin == safetypin){
    			printf("\n\t\t\tThe Admin Username is admin");
    			login();
			}
			else{
				printf("\n\t\t\tIncorrect! Please Try Again");
			}
			break;
		case 3:
			printf("\n\t\t\tAre you sure to cancel login? [y/n]: ");
			scanf(" %c", &cancel);
			
			if(cancel == 'y' || cancel == 'Y'){
				printf("\t\t\tGoing back to Main Menu...");
				sleep(1);
				mainmenu();
			}
			if(cancel != 'y' || cancel != 'Y'){
				login();
			}
		default:
			printf("\n\t\t\tNot in the options!");
			printf("\n\t\t\tGoing back to Main Menu...");
			break;
	}
    
}

void wrongpassword(){
	int pin;
	int choice = 0;
	char cancel;
	
    printf("\n\n\t\t\tIncorrect Password!\n\n");
    printf("\t\t\t[1] Re-enter Password\n");
    printf("\t\t\t[2] Enter Safety Pin\n");
    printf("\t\t\t[3] Cancel Login (Back to Main Menu)\n\n");
    
    printf("\t\t\tChoice: ");
    scanf("%d", &choice);
    
    switch(choice){
    	case 1:
    		login();
    		break;
    	case 2:
    		printf("\n\n\t\t\tEnter Safety Pin: ");
    		scanf("%d", &pin);
    		
    		if(pin == safetypin){
    			printf("\n\t\t\tThe Admin Password is admin");
    			login();
			}
			else{
				printf("\n\t\t\tIncorrect! Please Try Again");
			}
			break;
		case 3:
			printf("\n\t\t\tAre you sure to cancel login? [y/n]: ");
			scanf(" %c", &cancel);
			
			if(cancel == 'y' || cancel == 'Y'){
				printf("\t\t\tGoing back to Main Menu...");
				sleep(1);
				mainmenu();
			}
			if(cancel != 'y' || cancel != 'Y'){
				login();
			}
		default:
			printf("\n\t\t\tNot in the options!");
			printf("\n\t\t\tGoing back to Main Menu...");
			break;
	}
    
}

void adminportal(){
	Book book;
	int choice = 0;
	char back;
	char cancel;
	
	int bookId = 1000;
	char field[MAX_LENGTH];
	char newValue[MAX_LENGTH];
	
	system("cls");
		
		while(choice != 6){
			bookshelf();
			printf("\n\t\t\tADMIN PORTAL\n");
			printf("\t\t\t[1] Register Book\n");
			printf("\t\t\t[2] List Borrowed Books\n");
			printf("\t\t\t[3] List Book Returned\n");
			printf("\t\t\t[4] Available Books\n");
			printf("\t\t\t[5] Update Books\n");
			printf("\t\t\t[6] Logout\n\n");
			
			printf("\t\t\tChoice: ");
			scanf(" %d", &choice);
			
			switch(choice){
				case 1:
					printf("\n\t\t\t(i)Hint: Enter ""0"" to cancel this process\n");
				    printf("\t\t\tEnter the ID of the book: ");
				    scanf("%d", &book.id);
				    
				    if(book.id == 0){
				    	printf("\n\t\t\tAre you sure to cancel login? [y]: ");
						scanf(" %c", &cancel);
						
						if(cancel == 'y' || cancel == 'Y'){
							printf("\t\t\tGoing back to Admin Portal...");
							sleep(1);
							adminportal();
						}
						if(cancel != 'y' || cancel != 'Y'){
							registerbook(book);
						}
					}
					
					else {
						
				    printf("\t\t\tEnter the title of the book: ");
				    scanf(" %[^\n]s", book.title);
				
				    printf("\t\t\tEnter the author of the book: ");
				    scanf(" %[^\n]s", book.author);
				
				    printf("\t\t\tEnter the status of the book (Default: Available): ");
				    scanf(" %[^\n]s", book.status);
				    
				    printf("\t\t\tEnter the date borrowed of the book (Default: None): ");
				    scanf(" %[^\n]s", book.timedate);
				
				    registerbook(book);
					break;
					}
					break;
				case 2:
					listBorrowed();
					printf("\n\t\t\tGo back? [y]: ");
					scanf(" %c", &back);
					break;
				case 3:
					listReturned();
					printf("\n\t\t\tGo back? [y]: ");
					scanf(" %c", &back);
					break;
				case 4:
					availablebooks();
					printf("\n\t\t\tGo back? [y]: ");
					scanf(" %c", &back);
					break;
				case 5:
					availablebooks();
					printf("\n\t\t\t(i)Hint: Enter ""0"" to cancel this process\n");
					printf("\n\t\t\tEnter the book ID: ");
				    scanf("%d", &bookId);
				    
				
				    printf("\t\t\tEnter the field to update (id, title, author): ");
				    scanf("%s", field);
				
				    printf("\t\t\tEnter the new value: ");
				    scanf(" %[^\n]", newValue);
				    
				    if(bookId == 0){
				    	printf("\n\t\t\tAre you sure to cancel this process? [y]: ");
						scanf(" %c", &cancel);
						
						if(cancel == 'y' || cancel == 'Y'){
							printf("\t\t\tGoing back to Admin Portal...");
							sleep(1);
							adminportal();
							break;
						}
					}
					
					else {	
				    updateBookDetails(bookId, field, newValue);
					printf("\n\t\t\tGo back? [y]: ");
					scanf(" %c", &back);
					break;
					}
					break;
				case 6:
					printf("\n\t\t\tLogging out...");
					sleep(1);
					break;
				default:
					printf("\t\t\tNot in the options!");
					break;
			}
	}
}

void registerbook(Book book){
	FILE *file;
    char filename[] = "book_details.txt";

    file = fopen(filename, "a");
    if (file == NULL) {
        printf("\t\t\tUnable to open the file.\n");
        return;
    }

    fprintf(file, "ID: %d\n", book.id);
    fprintf(file, "Title: %s\n", book.title);
    fprintf(file, "Author: %s\n", book.author);
    fprintf(file, "Status: %s\n", book.status);
    fprintf(file, "Date and Time: %s\n", book.timedate);

    fclose(file);

    printf("\t\t\tBook registered successfully.\n");
    
    char back;
    printf("\t\t\tGo back? [y]: ");
	scanf(" %c", &back);
}

void listBorrowed() {
    FILE *file;
    char filename[] = "book_details.txt";
    Book book;
    int found = 0;

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("\t\t\tUnable to open the file.\n");
        return;
    }

    printf("\t\t\tBorrowed Books:\n");
    printf("\t\t\t+----+-----------------------------+-----------------------------+------------------+-----------------------------+\n");
    printf("\t\t\t| ID |           Title             |           Author            |   Student ID     |    Date and Time Borrowed   |\n");
    printf("\t\t\t+----+-----------------------------+-----------------------------+------------------+-----------------------------+\n");

    // Find the borrowed books
    while (fscanf(file, "ID: %d\n", &book.id) == 1) {
        fscanf(file, "Title: %[^\n]\n", book.title);
        fscanf(file, "Author: %[^\n]\n", book.author);
        fscanf(file, "Status: %[^\n]\n", book.status);
        fscanf(file, "Date and Time: %[^\n]\n", book.timedate);

        if (strcmp(book.status, "Available") != 0) {
            printf("\t\t\t| %-2d | %-27s | %-27s | %-16s | %-27s |\n", book.id, book.title, book.author, book.status, book.timedate);
            found = 1;
        }
    }

    printf("\t\t\t+----+-----------------------------+-----------------------------+------------------+-----------------------------+\n");

    if (!found) {
        printf("\t\t\tNo borrowed books found.\n");
    }

    fclose(file);
}

void listReturned() {
    FILE *file;
    char filename[] = "book_details.txt";
    Book book;
    int found = 0;

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("\t\t\tUnable to open the file.\n");
        return;
    }

    printf("\t\t\tReturned Books:\n");
    printf("\t\t\t+----+-----------------------------+-----------------------------+-----------------------------+\n");
    printf("\t\t\t| ID |           Title             |           Author            |    Date and Time Returned   |\n");
    printf("\t\t\t+----+-----------------------------+-----------------------------+-----------------------------+\n");

    // Find the returned books
    while (fscanf(file, "ID: %d\n", &book.id) == 1) {
        fscanf(file, "Title: %[^\n]\n", book.title);
        fscanf(file, "Author: %[^\n]\n", book.author);
        fscanf(file, "Status: %[^\n]\n", book.status);
        fscanf(file, "Date and Time: %[^\n]\n", book.timedate);

        if (strcmp(book.status, "Available") == 0) {
            printf("\t\t\t| %-2d | %-27s | %-27s | %-27s |\n", book.id, book.title, book.author, book.timedate);
            found = 1;
        }
    }

    printf("\t\t\t+----+-----------------------------+-----------------------------+-----------------------------+\n");

    if (!found) {
        printf("\t\t\tNo returned books found.\n");
    }

    fclose(file);
}

void availablebooks(){
	FILE *file;
    char filename[] = "book_details.txt";
    Book book;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("\t\t\tUnable to open the file.\n");
        return;
    }

    printf("\t\t\tAvailable Books:\n");
    printf("\t\t\t+----+-----------------------------+-----------------------------+\n");
    printf("\t\t\t| ID |           Title             |           Author            |\n");
    printf("\t\t\t+----+-----------------------------+-----------------------------+\n");

    while (fscanf(file, "ID: %d\n", &book.id) == 1) {
        fscanf(file, "Title: %[^\n]\n", book.title);
        fscanf(file, "Author: %[^\n]\n", book.author);
        fscanf(file, "Status: %[^\n]\n", book.status);
        fscanf(file, "Date and Time: %[^\n]\n", book.timedate);

        if (strcmp(book.status, "Available") == 0) {
            printf("\t\t\t| %-2d | %-27s | %-27s |\n", book.id, book.title, book.author);
        }
    }

    printf("\t\t\t+----+-----------------------------+-----------------------------+\n");

    fclose(file);
}

void updateBookDetails(int bookId, const char* field, const char* newValue) {
    FILE* file;
    FILE* tempFile;
    char filename[] = "book_details.txt";
    char tempFilename[] = "temp_book_details.txt";

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("\t\t\tUnable to open the file.\n");
        return;
    }

    tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("\t\t\tUnable to create the temporary file.\n");
        fclose(file);
        return;
    }

    Book book;
    int found = 0;

    while (fscanf(file, "ID: %d\n", &book.id) == 1) {
        fscanf(file, "Title: %[^\n]\n", book.title);
        fscanf(file, "Author: %[^\n]\n", book.author);
        fscanf(file, "Status: %[^\n]\n", book.status);
        fscanf(file, "Date and Time: %[^\n]\n", book.timedate);

        if (book.id == bookId) {
            found = 1;

            if (strcmp(field, "id") == 0) {
                book.id = atoi(newValue);
            } else if (strcmp(field, "title") == 0) {
                strncpy(book.title, newValue, MAX_LENGTH);
            } else if (strcmp(field, "author") == 0) {
                strncpy(book.author, newValue, MAX_LENGTH);
            } else {
                printf("Invalid field specified.\n");
                fclose(file);
                fclose(tempFile);
                remove(tempFilename);
                return;
            }
        }

        fprintf(tempFile, "ID: %d\n", book.id);
        fprintf(tempFile, "Title: %s\n", book.title);
        fprintf(tempFile, "Author: %s\n", book.author);
        fprintf(tempFile, "Status: %s\n", book.status);
        fprintf(tempFile, "Date and Time: %s\n", book.timedate);
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename(tempFilename, filename);

    if (found) {
        printf("\t\t\tBook details updated successfully.\n");
    } else {
        printf("\t\t\tBook not found.\n");
    }
}

void studentportal(){
	Student student;
	int choice = 0;
	int bookID;
	char studentID[MAX_LENGTH];
	char back;
	char cancel;
	
	int studentId;
	char field[MAX_LENGTH];
	char newValue[MAX_LENGTH];

	system("cls");
		
		while(choice != 5){
			bookshelf();
			printf("\n\t\t\tSTUDENT PORTAL\n");
			printf("\t\t\t[1] Register Student\n");
			printf("\t\t\t[2] Borrow Book\n");
			printf("\t\t\t[3] Return Book\n");
			printf("\t\t\t[4] Update Student\n");
			printf("\t\t\t[5] Main Menu\n\n");
			
			printf("\t\t\tChoice: ");
			scanf(" %d", &choice);
			
			switch(choice){
				case 1:
					printf("\n\t\t\t(i)Hint: Enter ""0"" to cancel this process\n");
					askstudent(&student);
					registerstudent(&student);
					break;
				case 2:
					availablebooks();
					
					printf("\n\t\t\t(i)Hint: Enter ""0"" to cancel this process\n");
					printf("\t\t\tEnter your student ID: ");
				    scanf(" %[^\n]s", studentID);
				    
				    if(strcmpi(studentID, "0") == 0){
				    	printf("\n\t\t\tAre you sure to cancel this process? [y]: ");
						scanf(" %c", &cancel);
						
						if(cancel == 'y' || cancel == 'Y'){
							printf("\t\t\tGoing back to Student Portal...");
							sleep(1);
							studentportal();
							break;
						}
					}
					
					else {	
				    printf("\t\t\tEnter the book ID you want to borrow: ");
				    scanf("%d", &bookID);
				
				    borrowbook(bookID, studentID);
				    printf("\n\t\t\tGo back? [y]: ");
					scanf(" %c", &back);
					break;
					}
					break;
				case 3:
					printf("\n\t\t\t(i)Hint: Enter ""0"" to cancel this process\n");
					printf("\t\t\tEnter your student ID: ");
				    scanf(" %[^\n]s", studentID);
				    
				    if(strcmpi(studentID, "0") == 0){
				    	printf("\n\t\t\tAre you sure to cancel this process? [y]: ");
						scanf(" %c", &cancel);
						
						if(cancel == 'y' || cancel == 'Y'){
							printf("\t\t\tGoing back to Student Portal...");
							sleep(1);
							studentportal();
						}
					}
					
					else {	
				    displayBorrowedBooks(studentID);
				
				    printf("\t\t\tEnter the book ID you want to return: ");
				    scanf("%d", &bookID);
				
				    returnbook(studentID, bookID);
				    printf("\n\t\t\tGo back? [y]: ");
					scanf(" %c", &back);
					break;
					}
					break;
				case 4:
					printf("\n\t\t\t(i)Hint: Enter ""0"" to cancel this process\n");
				    printf("\t\t\tEnter the student ID: ");
				    scanf("%d", &studentId);
				
				    printf("\t\t\tEnter the field to update (id, name, year): ");
				    scanf("%s", field);
				
				    printf("\t\t\tEnter the new value: ");
				    scanf(" %[^\n]", newValue);
				    
				    if(studentId == 0){
				    	printf("\n\t\t\tAre you sure to cancel this process? [y]: ");
						scanf(" %c", &cancel);
						
						if(cancel == 'y' || cancel == 'Y'){
							printf("\t\t\tGoing back to Student Portal...");
							sleep(1);
							studentportal();
							break;
						}
					}
					
					else {	
				    updateStudentDetails(studentId, field, newValue);
				    printf("\n\t\t\tGo back? [y]: ");
					scanf(" %c", &back);
					break;
					}
					break;
				case 5:
					break;
				default:
					printf("\t\t\tNot in the options!");
					break;
			}
	}
}

void askstudent(Student *student){
	char cancel;
	
	printf("\t\t\tEnter your Student ID: ");
	scanf("%d", &(student->id));
	
	if(student->id == 0){
		printf("\n\t\t\tAre you sure to cancel this process? [y]: ");
		scanf(" %c", &cancel);
						
		if(cancel == 'y' || cancel == 'Y'){
			printf("\t\t\tGoing back to Student Portal...");
			sleep(1);
			studentportal();
		}
	}
				
	printf("\t\t\tEnter your Name: ");
	scanf(" %[^\n]s", student->name);
				
	printf("\t\t\tEnter your Year: ");
	scanf("%d", &(student->year));
}

void registerstudent(const Student *student){
	char filename[MAX_LENGTH];
    sprintf(filename, "student_%d.txt", student->id);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("\t\t\tUnable to create file.\n");
        return;
    }

    fprintf(file, "Student ID: %d\n", student->id);
    fprintf(file, "Name: %s\n", student->name);
    fprintf(file, "Year: %d\n", student->year);

    fclose(file);

    printf("\n\t\t\tStudent information saved to %s.\n", filename);
    
    char back;
    printf("\n\t\t\tGo back? [y]: ");
	scanf(" %c", &back);
}

void borrowbook(int bookID, const char *studentID) {
    FILE *file;
    FILE *tempFile;
    char filename[] = "book_details.txt";
    char tempFilename[] = "temp_book_details.txt";
    Book book;
    int found = 0;

    // Open the original file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("\n\t\t\tUnable to open the file.\n");
        return;
    }

    // Open the temporary file in write mode
    tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("\n\t\t\tUnable to create temporary file.\n");
        fclose(file);
        return;
    }

    // Copy the book details to the temporary file
    while (fscanf(file, "ID: %d\n", &book.id) == 1) {
        fscanf(file, "Title: %[^\n]\n", book.title);
        fscanf(file, "Author: %[^\n]\n", book.author);
        fscanf(file, "Status: %[^\n]\n", book.status);
        fscanf(file, "Date and Time: %[^\n]\n", book.timedate);

        // Check if the book is available and is being borrowed
        if (book.id == bookID && strcmp(book.status, "Available") == 0) {
            found = 1;
            strcpy(book.status, studentID);
            
            //save current time upon borrowing
            time_t currentTime;
            time(&currentTime);
            
            char *dateTimeString = ctime(&currentTime);
            strcpy(book.timedate, dateTimeString);
        }

        // Write the book details to the temporary file
        fprintf(tempFile, "ID: %d\n", book.id);
        fprintf(tempFile, "Title: %s\n", book.title);
        fprintf(tempFile, "Author: %s\n", book.author);
        fprintf(tempFile, "Status: %s\n", book.status);
        fprintf(tempFile, "Date and Time: %s\n", book.timedate);
    }

    // Close the files
    fclose(file);
    fclose(tempFile);

    // Delete the original file
    remove(filename);

    // Rename the temporary file to the original file name
    rename(tempFilename, filename);

    // Display a message if the book was successfully borrowed
    if (found) {
        printf("\n\t\t\tBook with ID %d has been borrowed by student %s.\n", bookID, studentID);
    } else {
        printf("\n\t\t\tThe book with ID %d is not available for borrowing.\n", bookID);
        studentportal();
    }
}

void displayBorrowedBooks(const char *studentID) {
    FILE *file;
    char filename[] = "book_details.txt";
    Book book;
    int found = 0;

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("\t\t\tUnable to open the file.\n");
        return;
    }

    printf("\t\t\tBooks borrowed by student %s:\n", studentID);
    printf("\t\t\t+----+-----------------------------+-----------------------------+-----------------------------+\n");
    printf("\t\t\t| ID |           Title             |           Author            |    Date and Time Returned   |\n");
    printf("\t\t\t+----+-----------------------------+-----------------------------+-----------------------------+\n");

    // Find the books with the given student ID
    while (fscanf(file, "ID: %d\n", &book.id) == 1) {
        fscanf(file, "Title: %[^\n]\n", book.title);
        fscanf(file, "Author: %[^\n]\n", book.author);
        fscanf(file, "Status: %[^\n]\n", book.status);
        fscanf(file, "Date and Time: %[^\n]\n", book.timedate);

        if (strcmp(book.status, studentID) == 0) {
            printf("\t\t\t| %-2d | %-27s | %-27s | %-27s |\n", book.id, book.title, book.author, book.timedate);
            found = 1;
        }
    }

    printf("\t\t\t+----+-----------------------------+-----------------------------+-----------------------------+\n");

    if (!found) {
        printf("\t\t\tNo books found for student %s.\n", studentID);
        studentportal;
    }

    fclose(file);
}

void returnbook(const char *studentID, int bookID) {
    FILE *file;
    FILE *tempFile;
    char filename[] = "book_details.txt";
    char tempFilename[] = "temp_book_details.txt";
    Book book;
    int found = 0;

    // Open the original file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("\t\t\tUnable to open the file.\n");
        return;
    }

    // Open the temporary file in write mode
    tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("\t\t\tUnable to create temporary file.\n");
        fclose(file);
        return;
    }

    // Copy the book details to the temporary file
    while (fscanf(file, "ID: %d\n", &book.id) == 1) {
        fscanf(file, "Title: %[^\n]\n", book.title);
        fscanf(file, "Author: %[^\n]\n", book.author);
        fscanf(file, "Status: %[^\n]\n", book.status);
        fscanf(file, "Date and Time: %[^\n]\n", book.timedate);

        // Check if the book is borrowed by the student and is being returned
        if (strcmp(book.status, studentID) == 0 && book.id == bookID) {
            found = 1;
            strcpy(book.status, "Available");
            
            //save current time upon borrowing
            time_t currentTime;
            time(&currentTime);
            
            char *dateTimeString = ctime(&currentTime);
            strcpy(book.timedate, dateTimeString);
        }

        // Write the book details to the temporary file
        fprintf(tempFile, "ID: %d\n", book.id);
        fprintf(tempFile, "Title: %s\n", book.title);
        fprintf(tempFile, "Author: %s\n", book.author);
        fprintf(tempFile, "Status: %s\n", book.status);
        fprintf(tempFile, "Date and Time: %s\n", book.timedate);
    }

    // Close the files
    fclose(file);
    fclose(tempFile);

    // Delete the original file
    remove(filename);

    // Rename the temporary file to the original file name
    rename(tempFilename, filename);

    // Display a message if the book was successfully returned
    if (found) {
        printf("\t\t\tBook with ID %d has been returned by student %s.\n", bookID, studentID);
    } else {
        printf("\t\t\tNo book with ID %d was found for student %s.\n", bookID, studentID);
    }
}

void updateStudentDetails(int studentId, const char* field, const char* newValue) {
    char filename[MAX_LENGTH];
    sprintf(filename, "student_%d.txt", studentId);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("\t\t\tStudent Not Existing.\n");
        return;
    }

    char tempFilename[MAX_LENGTH];
    sprintf(tempFilename, "temp_student_%d.txt", studentId);

    FILE* tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("\t\t\tUnable to create the temporary file.\n");
        fclose(file);
        return;
    }

    Student student;
    int found = 0;

    while (fscanf(file, "Student ID: %d\n", &student.id) == 1) {
        fscanf(file, "Name: %[^\n]\n", student.name);
        fscanf(file, "Year: %d\n", &student.year);

        if (student.id == studentId) {
            found = 1;

            if (strcmp(field, "id") == 0) {
                student.id = atoi(newValue);
            } else if (strcmp(field, "name") == 0) {
                strncpy(student.name, newValue, MAX_LENGTH);
            } else if (strcmp(field, "year") == 0) {
                student.year = atoi(newValue);
            } else {
                printf("\t\t\tInvalid field specified.\n");
                fclose(file);
                fclose(tempFile);
                remove(tempFilename);  // Delete the temporary file
                return;
            }
        }

        fprintf(tempFile, "Student ID: %d\n", student.id);
        fprintf(tempFile, "Name: %s\n", student.name);
        fprintf(tempFile, "Year: %d\n", student.year);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(filename);               // Delete the original file
        rename(tempFilename, filename);  // Rename the temporary file to the original filename
        printf("\t\t\tStudent details updated successfully.\n");
    } else {
        remove(tempFilename);  // Delete the temporary file
        printf("\t\t\tStudent not found.\n");
    }
}
