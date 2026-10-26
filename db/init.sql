CREATE TABLE groups (
    id SERIAL PRIMARY KEY,
    name VARCHAR(50) NOT NULL
);

CREATE TABLE courses (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE teachers (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    city VARCHAR(50)
);

CREATE TABLE students (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    city VARCHAR(50),
    group_id INT REFERENCES groups(id)
);

CREATE TABLE grades (
    id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(id),
    course_id INT REFERENCES courses(id),
    grade INT CHECK (grade >= 0 AND grade <= 100)
);

INSERT INTO groups (name) VALUES
('Group 101'), 
('Group 102'), 
('Group 103'); --empty для перевірки

INSERT INTO courses (name) VALUES
('Math'), 
('Programming'), 
('Database');

INSERT INTO teachers (name, city) VALUES
('LALA1', 'Kyiv'),
('Fran', 'Lviv'),
('Mariia', 'Odesa'); -- В Одесі не буде студентів для перевірки

INSERT INTO students (name, city, group_id) VALUES
('Ol', 'Kyiv', 1),
('Mniti', 'Kyiv', 1),
('Dmitro', 'Lviv', 1), -- У Групі 101 3 студенти
('Ann', 'Lviv', 2),
('Roman', 'Kyiv', 2);

INSERT INTO grades (student_id, course_id, grade) VALUES
(1, 1, 95), (1, 2, 85),
(2, 1, 75), (2, 3, 90),
(3, 1, 88), (3, 2, 92),
(4, 3, 95), (4, 1, 90),
(5, 2, 60), (5, 3, 70);