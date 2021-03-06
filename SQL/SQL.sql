/*
 175. Combine Two Tables
 Easy

 Runtime: 221 ms, faster than 61.93%

 https://leetcode.com/problems/combine-two-tables/
 */
SELECT
    Person.FirstName,
    Person.LastName,
    Address.City,
    Address.State
FROM
    Person LEFT JOIN Address
ON
    Person.PersonId = Address.PersonId;


/*
 181. Employees Earning More Than Their Managers
 Easy

 Runtime: 306 ms, faster than 76.31%

 https://leetcode.com/problems/employees-earning-more-than-their-managers/
 */
SELECT
    A.Name AS 'Employee'
FROM
    Employee AS A,
    Employee AS B
WHERE
    A.ManagerId = B.Id AND
    A.Salary > B.Salary;

/*
 Same performance as above
 */
SELECT
    A.Name AS 'Employee'
FROM
    Employee AS A JOIN
    Employee AS B
ON
    A.ManagerId = B.Id AND
    A.Salary > B.Salary;


/*
 183. Customers Who Never Order
 Easy

 Solution 1:
 Runtime: 262 ms, faster than 44.55%

 Solution 2:
 Runtime: 254 ms, faster than 55.57%

 https://leetcode.com/problems/customers-who-never-order/
 */
SELECT
    Customers.Name AS 'Customers'
FROM
    Customers LEFT JOIN
    Orders
ON
    Customers.Id = Orders.CustomerId
WHERE
    Orders.CustomerId IS NULL;

SELECT
    Customers.Name AS 'Customers'
FROM
    Customers
WHERE
    Customers.Id NOT IN (
        SELECT
            Orders.CustomerId
        FROM
            Orders
);


/*
 196. Delete Duplicate Emails
 Easy

 Runtime: 648 ms, faster than 87.19%

 https://leetcode.com/problems/delete-duplicate-emails/
 */
DELETE FROM Person
WHERE Id NOT IN (
    SELECT *
    FROM (
             SELECT MIN(Id)
             FROM Person
             GROUP BY Email
         ) AS T
);


/*
 176. Second Highest Salary
 Easy

 Runtime: 139 ms, faster than 63.19%

 https://leetcode.com/problems/second-highest-salary/
 */
SELECT IFNULL((
        SELECT DISTINCT Salary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1
    ),
    NULL)
AS SecondHighestSalary;


/*
 177. Nth Highest Salary
 Medium

 Runtime: 216 ms, faster than 30.94%

 https://leetcode.com/problems/nth-highest-salary/
 */
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE NN INT;
    SET NN = N - 1;
    RETURN (
        SELECT IFNULL((
            SELECT DISTINCT Salary
            FROM Employee
            ORDER BY Salary DESC
            LIMIT 1 OFFSET NN
        ), NULL) AS SecondHighestSalary
    );
END;


/*
 197. Rising Temperature
 Easy

 Solution 1:
 Runtime: 1635 ms, faster than 5.0%

 Solution 2:
 Runtime: 713 ms, faster than 36.49%

 https://leetcode.com/problems/rising-temperature/
 */

SELECT Id FROM Weather AS CurrWeather
WHERE CurrWeather.Temperature > (
    SELECT PrevWeather.Temperature
    FROM Weather AS PrevWeather
    WHERE PrevWeather.RecordDate = SUBDATE(CurrWeather.RecordDate, 1)
);

SELECT CurrWeather.Id
FROM
    Weather AS CurrWeather INNER JOIN Weather AS PrevWeather
    ON PrevWeather.RecordDate = SUBDATE(CurrWeather.RecordDate, 1)
WHERE CurrWeather.Temperature > PrevWeather.Temperature;


/*
 182. Duplicate Emails
 Easy

 Runtime: 183 ms, faster than 95.62%

 https://leetcode.com/problems/duplicate-emails/
 */

SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;


/*
 184. Department Highest Salary
 Medium

 Solution 1: 3-way join
 318 ms, faster than 84.29%

 Solution 2: Join on department table with where condition
 413 ms, faster than 68.37%

 https://leetcode.com/problems/department-highest-salary/
 */

SELECT
    Department.Name AS Department,
    Employee.Name AS Employee,
    Employee.Salary
FROM ((
    SELECT DepartmentId, MAX(Salary) AS MaxSalary
    FROM Employee
    GROUP BY DepartmentId
) AS MaxSalaries
INNER JOIN Employee ON
    MaxSalaries.MaxSalary = Employee.Salary AND
    MaxSalaries.DepartmentId = Employee.DepartmentId
)
INNER JOIN Department ON
    Employee.DepartmentId = Department.Id;

SELECT
    Department.Name AS Department,
    Employee.Name AS Employee,
    Employee.Salary
FROM Employee INNER JOIN Department ON Employee.DepartmentId = Department.Id
WHERE (Employee.DepartmentId, Employee.Salary) IN (
    SELECT GroupedEmployees.DepartmentId, MAX(Salary)
    FROM Employee AS GroupedEmployees
    GROUP BY GroupedEmployees.DepartmentId
);

/*
 Example of subquery table join using the tables
 from Department Highest Salary, and the default test case
 */

SELECT *
FROM Department JOIN ((
    SELECT *
    FROM Employee
    WHERE
        Employee.Name = "Joe" AND
        Employee.Salary = 70000
    )
    AS Person)
    ON Department.Id = Person.DepartmentId;