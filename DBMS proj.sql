-- Create the orphanage database
CREATE DATABASE Orphan_db;
USE Orphan_db;

-- Table: Children
CREATE TABLE Children (
    child_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    age INT,
    gender ENUM('Male', 'Female', 'Other'),
    guardian_id INT,
    admission_date DATE,
    discharge_date DATE
);

-- Table: Guardians
CREATE TABLE Guardians (
    guardian_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    phone_number VARCHAR(15),
    address VARCHAR(100)
);

-- Table: Staff
CREATE TABLE Staff (
    staff_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    position VARCHAR(50),
    salary DECIMAL(10, 2),
    hire_date DATE
);

-- Table: Rooms
CREATE TABLE Rooms (
    room_id INT PRIMARY KEY AUTO_INCREMENT,
    room_number VARCHAR(10),
    capacity INT,
    available_beds INT
);

-- Table: Activities
CREATE TABLE Activities (
    activity_id INT PRIMARY KEY AUTO_INCREMENT,
    activity_name VARCHAR(100),
    activity_date DATE,
    staff_id INT
);

-- Table: Donations
CREATE TABLE Donations (
    donation_id INT PRIMARY KEY AUTO_INCREMENT,
    donor_name VARCHAR(100),
    donation_date DATE,
    amount DECIMAL(10, 2)
);

-- Table: MedicalRecords
CREATE TABLE MedicalRecords (
    record_id INT PRIMARY KEY AUTO_INCREMENT,
    child_id INT,
    record_date DATE,
    diagnosis VARCHAR(255),
    treatment VARCHAR(255)
);

-- Table: Expenses
CREATE TABLE Expenses (
    expense_id INT PRIMARY KEY AUTO_INCREMENT,
    expense_date DATE,
    description VARCHAR(255),
    amount DECIMAL(10, 2)
);

-- Table: Adoptions
CREATE TABLE Adoptions (
    adoption_id INT PRIMARY KEY AUTO_INCREMENT,
    child_id INT,
    adopter_name VARCHAR(100),
    adoption_date DATE
);

-- Insert sample data into Children table
INSERT INTO Children (first_name, last_name, age, gender, guardian_id, admission_date)
VALUES ('John', 'Doe', 8, 'Male', 1, '2023-01-15'),
       ('Jane', 'Smith', 10, 'Female', 2, '2022-11-20');

-- Insert sample data into Guardians table
INSERT INTO Guardians (first_name, last_name, phone_number, address)
VALUES ('Alice', 'Johnson', '555-123-4567', '123 Main St'),
       ('Michael', 'Williams', '555-987-6543', '456 Elm St');

-- Insert sample data into Staff table
INSERT INTO Staff (first_name, last_name, position, salary, hire_date)
VALUES ('Emily', 'Anderson', 'Social Worker', 50000, '2020-03-10'),
       ('James', 'Brown', 'Nurse', 60000, '2021-05-15');

-- Insert sample data into Rooms table
INSERT INTO Rooms (room_number, capacity, available_beds)
VALUES ('101', 4, 2),
       ('102', 6, 4);

-- Insert sample data into Activities table
INSERT INTO Activities (activity_name, activity_date, staff_id)
VALUES ('Arts and Crafts', '2024-03-15', 1),
       ('Outdoor Games', '2024-03-20', 2);

-- Insert sample data into Donations table
INSERT INTO Donations (donor_name, donation_date, amount)
VALUES ('ABC Foundation', '2024-02-10', 1000.00),
       ('XYZ Charity', '2024-03-05', 500.00);

-- Insert sample data into MedicalRecords table
INSERT INTO MedicalRecords (child_id, record_date, diagnosis, treatment)
VALUES (1, '2023-01-20', 'Common Cold', 'Rest and fluids'),
       (2, '2022-12-05', 'Minor injury', 'First aid applied');

-- Insert sample data into Expenses table
INSERT INTO Expenses (expense_date, description, amount)
VALUES ('2024-02-01', 'Food supplies', 1500.00),
       ('2024-03-10', 'Medical expenses', 800.00);

-- Insert sample data into Adoptions table
INSERT INTO Adoptions (child_id, adopter_name, adoption_date)
VALUES (2, 'Sarah Johnson', '2023-02-28');

-- Query 1: List all children currently in the orphanage.
SELECT * FROM Children WHERE discharge_date IS NULL;

-- Query 2: List all staff members hired before 2022.
SELECT * FROM Staff WHERE hire_date < '2022-01-01';

-- Query 3: Calculate the total number of available beds in the orphanage.
SELECT SUM(available_beds) AS total_available_beds FROM Rooms;

-- Query 4: List all activities scheduled for the current month (March 2024).
SELECT * FROM Activities WHERE MONTH(activity_date) = 3 AND YEAR(activity_date) = 2024;

-- Query 5: List all donations made in February 2024.
SELECT * FROM Donations WHERE MONTH(donation_date) = 2 AND YEAR(donation_date) = 2024;

-- Query 6: Calculate the total expenses incurred in 2024.
SELECT SUM(amount) AS total_expenses FROM Expenses WHERE YEAR(expense_date) = 2024;

-- Query 7: List all children with their guardian's information.
SELECT c.first_name AS child_first_name, c.last_name AS child_last_name,
       g.first_name AS guardian_first_name, g.last_name AS guardian_last_name
FROM Children c
JOIN Guardians g ON c.guardian_id = g.guardian_id;

-- Query 8: List all children who have been adopted.
SELECT c.first_name, c.last_name, a.adopter_name, a.adoption_date
FROM Children c
JOIN Adoptions a ON c.child_id = a.child_id;

-- Query 9: Calculate the average age of children in the orphanage.
SELECT AVG(age) AS average_age FROM Children WHERE discharge_date IS NULL;

-- Query 10: List all staff members along with the total number of activities they are responsible for.
SELECT s.first_name, s.last_name, COUNT(a.activity_id) AS total_activities
FROM Staff s
LEFT JOIN Activities a ON s.staff_id = a.staff_id
GROUP BY s.staff_id;

-- Query 11: List all medical records for a specific child (e.g., child_id = 1).
SELECT * FROM MedicalRecords WHERE child_id = 1;

-- Query 12: Calculate the total amount donated by each donor.
SELECT donor_name, SUM(amount) AS total_donation_amount
FROM Donations
GROUP BY donor_name;

-- Query 13: List all guardians along with the number of children they are responsible for.
SELECT g.first_name, g.last_name, COUNT(c.child_id) AS num_children
FROM Guardians g
LEFT JOIN Children c ON g.guardian_id = c.guardian_id
GROUP BY g.guardian_id;

-- Query 14: List all rooms with their current occupancy.
SELECT r.room_number, r.capacity, (r.capacity - r.available_beds) AS occupancy
FROM Rooms r;

-- Query 15: List all children admitted before 2023 and still in the orphanage.
SELECT * FROM Children WHERE admission_date < '2023-01-01' AND discharge_date IS NULL;

-- Query 16: List all expenses incurred for medical purposes.
SELECT * FROM Expenses WHERE description LIKE '%medical%';

-- Query 17: List all staff members with a salary greater than $50,000.
SELECT * FROM Staff WHERE salary > 50000;

-- Query 18: List all activities along with the staff member responsible for each activity.
SELECT a.activity_name, a.activity_date, s.first_name, s.last_name
FROM Activities a
JOIN Staff s ON a.staff_id = s.staff_id;

-- Query 19: Calculate the total number of adoptions in the orphanage.
SELECT COUNT(*) AS total_adoptions FROM Adoptions;

-- Query 20: List all children with their admission and discharge dates, if applicable.
SELECT first_name, last_name, admission_date, discharge_date FROM Children, Project demonstration
