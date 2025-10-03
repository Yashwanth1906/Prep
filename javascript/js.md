1. What is the Event Loop?

The event loop is the mechanism in JavaScript (and Node.js) that allows asynchronous, non-blocking execution even though JavaScript runs on a single thread.

Key idea:

JavaScript executes code synchronously line by line.

For operations that take time (like network requests, timers, or reading a file), we don’t want to block the entire thread.

The event loop manages these tasks in the background and executes them when ready.

2. Main Components

Call Stack – where your functions are executed synchronously.

Web APIs / Node APIs – handle async operations (e.g., setTimeout, HTTP requests).

Task Queue / Callback Queue – stores callbacks of async operations once they finish.

Event Loop – constantly checks: “Is the call stack empty? If yes, take the first task from the queue and push it onto the stack.”

3. Example
console.log('Start');

setTimeout(() => {
    console.log('Timeout 1');
}, 0);

Promise.resolve().then(() => {
    console.log('Promise 1');
});

console.log('End');

Step by Step Execution

console.log('Start'); → goes to call stack → prints Start.

setTimeout(..., 0); → Web API schedules the callback to run after 0ms → callback goes to task queue when timer expires.

Promise.resolve().then(...) → Promise callback goes to microtask queue. (Microtasks have higher priority than the task queue.)

console.log('End'); → prints End.

Event Loop Behavior

Call stack is now empty.

Microtask queue has Promise 1 → executes it → prints Promise 1.

Task queue has Timeout 1 → executes it → prints Timeout 1.

Output
Start
End
Promise 1
Timeout 1


✅ Notice how Promises run before setTimeout, even if the timeout is 0ms. That’s because microtasks are executed before the task queue.

4. Visual Diagram
Call Stack:          Task Queue:          Microtask Queue:
-------------        -------------        ----------------
console.log           setTimeout           Promise.then
Start                 Timeout 1
End


Event loop checks:

Call stack empty → run microtasks → prints Promise 1

Call stack empty → run tasks → prints Timeout 1

5. Why Event Loop Matters

Without the event loop:

JavaScript couldn’t do async tasks.

Timers, HTTP requests, or DB queries would block the entire thread.

With event loop:

JS can handle multiple async tasks efficiently on a single thread.

Node.js and browsers can be highly responsive.