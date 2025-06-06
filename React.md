# React

React’s architecture has **three main layers**:

1. **Renderer (ReactDOM / React Native / etc.)**
2. **Reconciler (React Core)**
3. **Scheduler (Fiber)**

## 1. **Renderer** — Connects React to the actual platform

- React by itself doesn’t know if you're building for the web, mobile, or even a game engine.
- So it delegates the rendering part to something called a **renderer**.
- Converts **React elements** into **actual UI elements**.
- For the web, `react-dom` takes your React tree and creates **DOM nodes**.

## 2. **Reconciler** — Decides what needs to change

When state changes, React:

- Calls your function/component again to **re-render** (it’s functional).
- But it doesn’t touch the DOM immediately.

Instead, it uses the **Reconciler** to:

- Compare the new React tree with the old one.
- Figure out what has **actually changed** (called **diffing**).
- Then tells the Renderer, “Update this, not the whole thing.”

This makes React **efficient** and **fast** — it doesn’t reload the whole UI, just changes the minimal parts.

## 3. **Scheduler (Fiber)** — Controls timing and priority

This is one of the **smartest and most misunderstood** parts of React.

React’s old engine was **stack-based** and synchronous — it would lock the browser until rendering was done. That caused lag and jank.

So in 2017, React got a new core architecture called **Fiber**.

### Fiber lets React:

- **Pause work**, do urgent things (like handling a button click), then come back.
- **Break work into chunks** and render in pieces.
- Give different **priority** to different tasks.

Main Features:

- **Virtual DOM**: Lightweight JS representation of the actual DOM.
- **Component-based architecture**: UIs are broken into reusable functions.
- **Declarative UI**: You describe *what* UI should look like, React figures out *how* to make it happen.
- **Unidirectional Data Flow**: Data flows from parent → child. (The things are passed as props from the parent to the child)
- **Keys**: Help React identify elements between renders.
- **Hooks**: Let you “hook into” state and lifecycle in function components.

## What is **JSX**?

JSX stands for **JavaScript XML**. It’s a **syntax extension for JavaScript** that lets you write HTML-like code inside JavaScript.

const element = <h1>Hello, world!</h1>;

But under the hood, React transforms this into:
const element = React.createElement("h1", null, "Hello, world!");

const element = React.createElement(
"button",                        // Type of element
{ className: "click-btn" },      // Props (attributes)
"Click"                          // Children (text, elements, etc.)
);

### ⚠️ Hooks must follow **two rules**:

1. Call them only at the **top level** of your component (not inside loops or conditions).
2. Only call hooks from **React components** or **custom hooks**.

### 2. 🧬 `useEffect`

**Runs side effects after render.** It replaces:

- `componentDidMount`
- `componentDidUpdate`
- `componentWillUnmount`
- If `[]` → runs once after mount
- If `[count]` → runs when `count` changes
- If no array → runs after every render

Common uses:

- Fetching data
- Adding/removing event listeners
- Subscriptions

### 3. 📦 `useContext`

**Reads data from a context provider.**

```jsx
const theme = useContext(ThemeContext);
```

Used when you have data (like theme, auth, language) shared across many components.

### 4. 🔗 `useRef`

**Creates a mutable reference that persists across renders.**

```jsx
const inputRef = useRef(null);
```

- Can be used to directly **access DOM elements**
- Or store **mutable values** without causing re-renders

```jsx
<input ref={inputRef} />
<button onClick={() => inputRef.current.focus()}>Focus</button>
```

Also good for:

- Tracking previous state
- Tracking timers/intervals

### 5. 🧮 `useMemo`

**Memoizes a computed value to avoid recalculating unless dependencies change.**

### 6. 📞 `useCallback`

**Memoizes a function.**

```jsx
const handleClick = useCallback(() => {
  doSomething(id);
}, [id]);
```

Useful when:

- You pass functions to **child components**
- And want to avoid re-renders unless necessary

Difference from `useMemo`:

- `useMemo` → memoizes **value**
- `useCallback` → memoizes **function**

### 11. 🌊 `useTransition`

Mark state updates as **non-urgent** — for smoother UX.

### 12. 🐢 `useDeferredValue`

Defers rendering a value until less urgent updates are done.

```jsx
const deferredValue = useDeferredValue(searchQuery);
```

Useful when:

- UI is laggy during fast typing
- Allows input to be immediate while delaying expensive UI

| Hook | Purpose |
| --- | --- |
| `useState` | Local state management |
| `useEffect` | Side effects (data fetch, subscriptions) |
| `useContext` | Access context values |
| `useRef` | Access DOM nodes or persist values |
| `useMemo` | Memoize expensive calculations |
| `useCallback` | Memoize functions |
| `useReducer` | Advanced state logic with actions |
| `useLayoutEffect` | Layout-related effects before paint |
| `useImperativeHandle` | Customize exposed ref behavior |
| `useDebugValue` | Label for custom hooks in DevTools |
| `useTransition` | Mark updates as low-priority (React 18) |
| `useDeferredValue` | Delay rendering based on low-priority input (React 18) |

## Props Drilling:

**Prop drilling** means passing props from a parent → child → grandchild → great-grandchild, **even if some components in between don’t need that data**.

Solution?

- Use **React Context** to avoid drilling
- Or manage global state via Redux, Zustand, Jotai, etc.

## Lifting State Up

When **two or more components need access to the same state**, you “lift” that state **up to their common ancestor** and pass it down via props. This keeps state in one place and avoids duplicate/conflicting data.

Passing Callbacks to Children

This is **how children communicate back to parents** in React.

The child can't directly update the parent’s state, but you can give the child a **function** to call, and the parent handles the update.

```jsx
function Parent() {
  const [count, setCount] = useState(0);
  const handleClick = () => setCount(count + 1);
  return (
    <div>
      <Child onClick={handleClick} />
      <p>Count: {count}</p>
    </div>
  );
}
function Child({ onClick }) {
  return <button onClick={onClick}>Click me</button>;
}
```

## What are Error Boundaries?

In React, **Error Boundaries** are components that catch **JavaScript errors** in their child component tree, log them, and display a **fallback UI** instead of breaking the entire app.

Without error boundaries:

- A single JS error in a child component **crashes the whole React tree**.
    
    With error boundaries:
    
- You can **gracefully handle** that error and show a user-friendly message or retry option

---

---

```jsx
Class ErrorBoundary extends React.Component {
  constructor(props) {
    super(props);
    this.state = { hasError: false };
  }
  static getDerivedStateFromError(error) {
    return { hasError: true };
  }
  componentDidCatch(error, info) {
    console.error("Error caught by ErrorBoundary:", error);
  }
  render() {
    if (this.state.hasError) {
      return <h2>Something went wrong 😢</h2>;
    }
    return this.props.children;
  }
}
```

```jsx
<ErrorBoundary>
  <MyComponent />
</ErrorBoundary>
```

## Lazy Loading Components (`React.lazy` + `Suspense`)

Load components **only when needed**, instead of all at once.

```jsx
const LazyComponent = React.lazy(() => import('./MyComponent'));
function App() {
  return (
    <Suspense fallback={<p>Loading...</p>}>
      <LazyComponent />
    </Suspense>
  );
}
```

### Why use it:

- **Improves initial load time**
- Great for:
    - Routes
    - Modals
    - Tabs
    - Feature flags

### Things to know:

- Works only with **default exports**
- Needs to be wrapped with `<Suspense>`

## When Re-renders Happen in React

A component re-renders when:

- Its **state changes**
- Its **props change**
- Its **parent re-renders** (even if props didn’t change)
- A **context it uses changes**
- A **key** on the component changes

### **Automatic Batching**

Batching means React groups state updates into one render.

### In React 17 and earlier:

Only DOM event updates were batched:

```
function handleClick() {
  setCount(c => c + 1); // causes re-render
  setFlag(true);        // causes another re-render
}
```

These would trigger **2 re-renders**.

### In React 18:

React batches **state updates inside timeouts, promises, fetches**, etc.

```
setTimeout(() => {
  setCount(c => c + 1);
  setFlag(true);
}, 1000);
```

Now: Just **1 re-render**.

That’s **automatic** batching. No work needed on your end.

### `startTransition` – Mark Updates as Low Priority

Let’s say you type into a search box and the UI becomes laggy. That’s because React is rendering a big list *at the same priority* as your typing.

You can now **tell React** which updates are **non-urgent**.

```
Import { startTransition } from 'react';
function handleInputChange(e) {
  setInput(e.target.value); // urgent
  startTransition(() => {
    setSearchResults(filterItems(e.target.value)); // low priority
  });
}
```

### `useDeferredValue` – Lazy update of a value

This hook lets you **defer updating** a value until the browser has time.

Example: Slow component that renders a big filtered list.

```
const deferredSearch = useDeferredValue(searchTerm);
const results = items.filter(item => item.includes(deferredSearch));
```

`deferredSearch` lags behind a bit — this **smooths the UI** while React keeps it responsive.

Great for:

- Search-as-you-type
- Live previews
- Heavy recomputations

### What is Hydration?

Hydration = taking the static HTML from the server and attaching React’s event handlers to make it interactive.

In React 18, hydration is **streaming and non-blocking**, so parts of the page can start interacting **faster**.

```jsx
import { hydrateRoot } from 'react-dom/client';
hydrateRoot(document.getElementById('root'), <App />);
```

## What is Recoil?

**Recoil** is a **state management library** for React apps, developed by Facebook. It introduces a model that is **closer to React's mental model** — **declarative**, **reactive**, and **composable**.

Recoil uses **atoms** and **selectors** to manage global and derived state in a React-y way.

---

## Why use Recoil?

Recoil is great when:

- You have **complex shared state**
- You need **fine-grained control** over which components re-render
- You want to avoid the boilerplate of Redux
- You want **derived/computed state** (like Vue’s computed properties)
- You’re working with **Concurrent React** (Recoil is concurrency-friendly)

---

## Core Concepts

### 1. **Atoms**

Atoms are units of state — kind of like a `useState`, but **shared** across your app.

```
js
CopyEdit
import { atom } from 'recoil';

export const countAtom = atom({
  key: 'countAtom',       // unique ID
  default: 0              // initial value
});

```

To use this atom in a component:

```
import { useRecoilState } from 'recoil';
import { countAtom } from './store';
function Counter() {
  const [count, setCount] = useRecoilState(countAtom);
  return <button onClick={() => setCount(count + 1)}>{count}</button>;
}
```

### Key behavior:

- When `countAtom` changes, all components that use it **re-render automatically**
- You can read/write to it using `useRecoilState`, `useRecoilValue`, or `useSetRecoilState`

### **Selectors**

Selectors are **derived values** — like formulas based on atoms.

```jsx
import { selector } from 'recoil';
import { countAtom } from './store';
export const doubleCount = selector({
  key: 'doubleCount',
  get: ({ get }) => get(countAtom) * 2
});
```

To use it:

```jsx
import { useRecoilValue } from 'recoil';
import { doubleCount } from './store';
function ShowDouble() {
  const doubled = useRecoilValue(doubleCount);
  return <div>Double: {doubled}</div>;
}
```

Selectors are:

- **Cached** automatically (like `useMemo`)
- **Reactive** — update when their dependencies change
- Great for **computed state** (e.g., filters, totals, visibility)

### **RecoilRoot**

Wrap your app in a `RecoilRoot` to enable Recoil state:

```jsx
import { RecoilRoot } from 'recoil';
function App() {
  return (
    <RecoilRoot>
      <MainApp />
    </RecoilRoot>
  );
}
```