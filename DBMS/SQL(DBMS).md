## SQL Things to remember

- IS keyword is uesd to map to null values in a field.
- LIKE Keyword is used to match patterns in string like 'C%' takes all the words starting with 'C'.
- concat keyword is used to concatenate column values and normal values.
- count keyword is used to count the no of entries.
- (1....10) we can put elements and put in to check where id is present in the tuple or not.
- To get the year from the Date type in SQL we need to use YEAR(dob).
- To sort the values using more than one condition put all the condition followed by ',' using order by keyword.
- Scalar Subquery or Subquery in the SELECT list.
    eg : SELECT ((select count(*) from patients where gender = 'M') as male_count; (select count(*) from patients where gender = 'F') as female_count);
    It is used to select the results of two separate queries.
- We can group by using more than one column. by using ',' .
- we can use DESC to sort in descending order.
- we can write conditions inside aggregate function.
    sum(
        case
            when condition then do,
            when condition2 then do2,
        end
    )



### Select Query Syntax:
- SELECT field1 as name1, .... from table_name where condition;

### Update Query syntax:
- UPDATE table_name SET column1 = value1, column2 = value2, ... WHERE condition;


## SQL Joins - Description and Syntax

### 1. INNER JOIN

**Description:**  
Returns only the rows where there is a match in both tables.

**Syntax:**
```sql
SELECT columns
FROM TableA
INNER JOIN TableB ON TableA.common_column = TableB.common_column;
```

### 2. LEFT JOIN (or LEFT OUTER JOIN)

Description:
Returns all rows from the left table and the matched rows from the right table. If no match, NULLs are returned from the right side.

Syntax:

```sql
SELECT columns
FROM TableA
LEFT JOIN TableB ON TableA.common_column = TableB.common_column;
```

### 3. RIGHT JOIN (or RIGHT OUTER JOIN)

Description:
Returns all rows from the right table and the matched rows from the left table. If no match, NULLs are returned from the left side.

Syntax:

```sql
SELECT columns
FROM TableA
RIGHT JOIN TableB ON TableA.common_column = TableB.common_column;
```
### 4. FULL JOIN (or FULL OUTER JOIN)

Description:
Returns all rows when there is a match in one of the tables. If there is no match, NULLs are returned from the table without a match.

Syntax:

```sql
SELECT columns
FROM TableA
FULL OUTER JOIN TableB ON TableA.common_column = TableB.common_column;
```
### 5. CROSS JOIN

Description:
Returns the Cartesian product of both tables—each row in the first table is combined with every row in the second table.

Syntax:

```sql
SELECT columns
FROM TableA
CROSS JOIN TableB;
```


## SQL: GROUP BY, ORDER BY, and HAVING

---

### 1. GROUP BY

**Purpose:**  
`GROUP BY` is used to group rows that have the same values in specified columns. It's typically used with aggregate functions like `COUNT()`, `SUM()`, `AVG()`, etc.

**Syntax:**
```sql
SELECT column, AGGREGATE_FUNCTION(column)
FROM table
GROUP BY column;
```

Example:

```sql


SELECT department, COUNT(*) AS total_employees
FROM employees
GROUP BY department;
Groups employees by department and counts how many are in each.
```
### 2. ORDER BY
Purpose:
ORDER BY is used to sort the result set by one or more columns, either in ascending (ASC) or descending (DESC) order.

Syntax:

```sql


SELECT *
FROM table
ORDER BY column [ASC | DESC];
```
Example:

```sql


SELECT first_name, salary
FROM employees
ORDER BY salary DESC;
Retrieves employees sorted by salary, from highest to lowest.
```
### 3. HAVING
Purpose:
HAVING is used to filter groups after aggregation. It's like a WHERE clause but for use with GROUP BY.

Syntax:

```sql


SELECT column, AGGREGATE_FUNCTION(column)
FROM table
GROUP BY column
HAVING condition;
```
Example:

```sql


SELECT department, COUNT(*) AS total_employees
FROM employees
GROUP BY department
HAVING COUNT(*) > 5;
Returns departments with more than 5 employees.
```


## SQL Set Operators: UNION, UNION ALL, INTERSECT, EXCEPT

SQL provides several **set operators** to combine results from multiple `SELECT` queries. The most common ones are:

1. UNION  
2. UNION ALL  
3. INTERSECT  
4. EXCEPT (or MINUS in some databases)

---

### 1. UNION

**Description:**  
`UNION` combines the result sets of two or more `SELECT` statements and removes **duplicate rows** from the final result.

**Syntax:**
```sql
SELECT column1, column2 FROM table1
UNION
SELECT column1, column2 FROM table2;
```


Rules:

- Each SELECT must have the same number of columns.
- Columns must be of compatible data types.
- Automatically performs DISTINCT to remove duplicates.

### 2. UNION ALL
Description:
UNION ALL combines the result sets of two or more SELECT statements and includes all rows, including duplicates.

Syntax:

```sql
Copy
Edit
SELECT column1, column2 FROM table1
UNION ALL
SELECT column1, column2 FROM table2;
Differences from UNION:
```

UNION ALL is faster because it does not sort or remove duplicates.

Returns all rows, even if they are duplicated.

### 3. INTERSECT
Description:
INTERSECT returns only the rows that are common to both SELECT queries.

Syntax:

```sql
Copy
Edit
SELECT column1, column2 FROM table1
INTERSECT
SELECT column1, column2 FROM table2;
```
Notes:

Not supported in some databases like MySQL (but available in PostgreSQL, SQL Server, Oracle).

Automatically removes duplicates in the intersection.

### 4. EXCEPT / MINUS
Description:
EXCEPT (or MINUS in Oracle) returns rows from the first query that are not present in the second query.

Syntax (PostgreSQL / SQL Server):

```sql
Copy
Edit
SELECT column1, column2 FROM table1
EXCEPT
SELECT column1, column2 FROM table2;
```
Syntax (Oracle):

```sql
Copy
Edit
SELECT column1, column2 FROM table1
MINUS
SELECT column1, column2 FROM table2;
```
Notes:

Removes duplicates from the result.

Only includes records unique to the first query.