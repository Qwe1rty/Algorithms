/*
 175. Combine Two Tables
 Easy

 speed: 221 ms, faster than 61.93%

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

 speed: 306 ms, faster than 76.31%

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

 speed: 262 ms, faster than 44.55%

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

/*
 speed: 254 ms, faster than 55.57%
 */
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

 speed: 648 ms, faster than 87.19%

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

 speed:139 ms, faster than 63.19%

 https://leetcode.com/problems/second-highest-salary/
 */
SELECT IFNULL((
        SELECT DISTINCT Salary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1
    ),
    NULL)
AS SecondHighestSalary