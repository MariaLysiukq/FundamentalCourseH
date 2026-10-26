SELECT city, COUNT(*) AS students_count
FROM students
GROUP BY city;

SELECT course_id, AVG(grade) AS average_grade
FROM grades
GROUP BY course_id
HAVING AVG(grade) > 85;

SELECT group_id, COUNT(*) AS students_count
FROM students
GROUP BY group_id
HAVING COUNT(*) > 2;

SELECT c.name AS course_name, COUNT(g.grade) AS grades_count
FROM courses c
JOIN grades g ON c.id = g.course_id
GROUP BY c.name;

SELECT gr.name AS group_name, AVG(g.grade) AS average_grade
FROM groups gr
LEFT JOIN students s ON gr.id = s.group_id
LEFT JOIN grades g ON s.id = g.student_id
GROUP BY gr.name;

SELECT course_id, student_id, grade
FROM grades g1
WHERE grade = (
    SELECT MAX(grade) 
    FROM grades g2 
    WHERE g1.course_id = g2.course_id
);

SELECT name, 'Student' AS role 
FROM students
UNION ALL
SELECT name, 'Teacher' AS role 
FROM teachers;

SELECT city FROM teachers
EXCEPT
SELECT city FROM students;