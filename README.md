# Library-Management-System-in-C-language
This is my 1st year project in C language named as "Library Management System" that uses structures, functions, and file handling.

Capabilities:
1. Has admin portal for:
  a. Register book (this includes Book Id, Title, and Author)
  b. View Returned Book (with time and date)
  c. View Borrowed Book (with time, date, and Student Id of the borrower)
  d. View Available Book (books with "Available" status)
  e. Update Book Status
  
2. Has student portal for:
  a. Register Student (this includes School Id, Name, and Year Level)
  b. Borrow Book (by asking for School Id and the Book Id)
  c. Return Book (by asking for School Id and the Book Id)
  d. Update Student Info
  
Limitations:
1. Book has only have 1 copy
2. Admin login has low security level with default username and password of "admin"
3. Safety pin for able to forgot username/password is also low security level with default of "1234"
4. School Id is advisable to use only 4 digits as uniformity but the program will be restricted to register 9999 students
