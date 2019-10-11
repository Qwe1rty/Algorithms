/*
 Example table schemas, for MySQL 5.6
 Including seed data
 */
CREATE TABLE authors (
    author_id INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
    author_name TEXT NOT NULL,
    age INTEGER UNSIGNED NOT NULL,
    PRIMARY KEY (author_id)
);

CREATE TABLE publishers (
    publisher_id INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
    publisher_name TEXT NOT NULL,
    location TEXT NOT NULL,
    PRIMARY KEY (publisher_id)
);

CREATE TABLE books (
    book_id INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
    book_title TEXT NOT NULL,
    author_id INTEGER UNSIGNED NOT NULL,
    publisher_id INTEGER UNSIGNED NOT NULL,
    PRIMARY KEY (book_id),
    FOREIGN KEY (author_id) REFERENCES authors(author_id),
    FOREIGN KEY (publisher_id) REFERENCES publishers(publisher_id)
);

INSERT INTO authors(author_name, age)
VALUES
    ("John Doe", 34),
    ("Bob Smith", 49),
    ("Larry Dale", 29),
    ("Eric Levalier", 41),
    ("Max Savinsky", 33),
    ("Ryan O'Connor", 36),
    ("Sarah Langley", 42),
    ("Jack Smith", 34),
    ("Meredith Jane", 30),
    ("Neil Williams", 31),
    ("Scott Meyers", 45),
    ("Frank Howards", 38),
    ("Alex Gonzales", 42),
    ("Hubert Locke", 40),
    ("Miller Johnson", 31),
    ("Mary Jane", 28);

INSERT INTO publishers(publisher_name, location)
VALUES
    ("O'Reilly", "New York"),
    ("Slashdot", "New York"),
    ("Elsevier", "Austin"),
    ("For Dummies", "Los Angeles"),
    ("Springer", "San Francisco");

INSERT INTO books(book_title, author_id, publisher_id)
VALUES
    ("An Introduction to Python", 3, 1),
    ("Understanding SQL", 10, 1),
    ("Writing Optimized SQL", 7, 1),
    ("COBOL in the Modern Age", 9, 1),
    ("The JavaScript Ecosystem", 3, 1),
    ("High-Performance C++", 2, 1),
    ("Enterprise Java Solutions", 8, 1),
    ("Database Distribution", 7, 1),
    ("Relational Database Schema Design", 11, 1),
    ("Understanding Hadoop", 16, 1),
    ("DevOps Cookbook", 14, 1),
    ("What is Kubernetes?", 3, 1),
    ("Microservice Architecture Issues", 8, 1),
    ("The Pythonic Way", 6, 1),
    ("Java Performance", 3, 1),
    ("YAML and You", 5, 1),
    ("Building Scalable Systems", 1, 1),
    ("The TypeScript Handbook", 12, 2),
    ("Redux Revolution", 11, 2),
    ("AWS Administration", 8, 2),
    ("Golang Design Patterns", 6, 2),
    ("7 Concurrency Architectures", 3, 2),
    ("Java 8 and Beyond", 15, 2),
    ("What is Serverless?", 11, 2),
    ("The Lambda Takeover", 6, 2),
    ("Golang for the Masses", 4, 2),
    ("Dockerize All the Things", 14, 2),
    ("The MySQL Encyclopedia", 12, 2),
    ("The Bash Hackers", 16, 2),
    ("Distributed Algorithms", 2, 2),
    ("Rust, the New Systems King", 1, 3),
    ("Networking Fundamentals", 14, 3);

/*
 Example queries
*/
SELECT *
FROM authors JOIN books ON authors.author_id = books.author_id
WHERE age >= 40;