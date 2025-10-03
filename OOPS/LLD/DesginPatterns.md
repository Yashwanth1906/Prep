# Design Patterns in c++

### 1. Creational Patterns 

**Focus**: Object creation—how to instantiate or configure objects so they're easy to use, flexible, maintainable.  
**Examples**:

-   **Singleton**: ensures only one instance of a class exists.
    
-   **Factory Method**: defines an interface for creating an object, but lets subclasses decide which class to instantiate.
    
-   **Abstract Factory**: provides interfaces for creating families of related objects.
    
-   **Builder**: constructs a complex object step-by-step.
    
-   **Prototype**: creates objects by cloning an existing instance.
    

----------

### 2. Structural Patterns 

**Focus**: Composition—how to build larger structures from classes or objects.  
**Examples**:

-   **Adapter**: allows classes with incompatible interfaces to work together.
    
-   **Bridge**: decouples abstraction from implementation so both can vary independently.
    
-   **Composite**: lets you treat individual objects and compositions uniformly.
    
-   **Decorator**: adds responsibilities to objects dynamically.
    
-   **Facade**: provides a simplified interface to a complex subsystem.
    
-   **Flyweight**: reduces the number of objects by sharing common parts.
    
-   **Proxy**: provides a surrogate or placeholder to control access to another object.
    

----------

### 3. Behavioral Patterns 

**Focus**: Algorithms and object communication—how objects interact and distribute responsibility.  
**Examples**:

-   **Chain of Responsibility**: passes request along a chain of handlers.
    
-   **Command**: encapsulates a request as an object.
    
-   **Interpreter**: defines a representation for grammar and an interpreter.
    
-   **Iterator**: provides a way to access elements of a collection sequentially.
    
-   **Mediator**: centralizes complex communications and control logic.
    
-   **Memento**: captures and restores an object’s state.
    
-   **Observer**: defines a one-to-many dependency so that when one object changes state, all dependents are notified.
    
-   **State**: allows an object to alter its behavior when its internal state changes.
    
-   **Strategy**: defines a family of algorithms and makes them interchangeable via delegation.
    
-   **Template Method**: defines the skeleton of an algorithm, deferring some steps to subclasses.
    
-   **Visitor**: represents an operation to be performed on elements of an object structure.


### Singleton Design Pattern:
#### Intent & Purpose

The **Singleton pattern** ensures a class has **exactly one instance** and provides a **single global access point** to it [IONOS+15Refactoring Guru+15GitHub+15](https://refactoring.guru/design-patterns/singleton?utm_source=chatgpt.com).

It's ideal when representing shared, centralized resources—like a **database connection**, **configuration manager**, or **logger**—without resorting to unsafe global variables [Reddit+15Refactoring Guru+15Jointaro+15](https://refactoring.guru/design-patterns/singleton?utm_source=chatgpt.com).

----------

#### Structure & Core Mechanics

All Singleton implementations share these elements [Reddit+5Wikipedia+5Reddit+5](https://en.wikipedia.org/wiki/Singleton_pattern?utm_source=chatgpt.com):

1.  **Private static instance variable** – holds the sole object.
    
2.  **Private constructor** – prevents direct instantiation.
    
3.  **Public static accessor** (often `getInstance()`) – initializes the instance (if not created) and returns it.
    

A typical C++ structure:
```c++
class Singleton {
private:
    static Singleton* instance;
    Singleton() { /* init resource */ }
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance() {
        if (!instance) instance = new Singleton();
        return *instance;
    }

    // business methods...
};
```

#### Real-World Use Cases
-   **Logging** – shared logging instance
-   **Global configuration** – single object managing settings
-   **Database connection manager** – one connection pool across the app
    
-   **Printer resource management** – only one printer object for all users

#### Benefits

-   **Single shared instance** – ensures there’s only one object.
    
-   **Controlled global access** – without risk of literal global variables
-   **Lazy initialization** – defers creation until needed, saving resources

### Factory Method

#### Intent and Definition

**Factory Method** is a **creational pattern** originating from the GoF. Its goal is to:

> “Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.” [Javatpoint+15Wikipedia+15CodeProject+15](https://en.wikipedia.org/wiki/Factory_method_pattern?utm_source=chatgpt.com)

It encapsulates object creation, allowing clients to rely on abstractions rather than concrete classes.

----------

#### 2. Participants & UML Overview

-   **Product**: interface or abstract class defining objects created.
    
-   **ConcreteProduct**: defines actual objects created.
    
-   **Creator**: declares the factory method and may include core logic.
    
-   **ConcreteCreator**: overrides the factory method to return a specific product.
```
#include <iostream>
#include <memory>
#include <string>

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Drawing a Circle\n"; }
};

class Square : public Shape {
public:
    void draw() override { std::cout << "Drawing a Square\n"; }
};

class ShapeFactory {
public:
    static std::unique_ptr<Shape> create(const std::string& type) {
        if (type == "circle") return std::make_unique<Circle>();
        if (type == "square") return std::make_unique<Square>();
        return nullptr;
    }
};

int main() {
    auto a = ShapeFactory::create("circle");
    if (a) a->draw();  // Output: Drawing a Circle

    auto b = ShapeFactory::create("square");
    if (b) b->draw();  // Output: Drawing a Square
}
```

Tyepscript : 

```
// Product interface
interface Button {
  render(): void;
}

// Concrete products
class DefaultButton implements Button {
  render() { console.log("Default button"); }
}
class PrimaryButton implements Button {
  render() { console.log("Primary button"); }
}
class DangerButton implements Button {
  render() { console.log("Danger button"); }
}

// Factory
class ButtonFactory {
  static create(type: string): Button {
    if (type === "default") return new DefaultButton();
    if (type === "primary") return new PrimaryButton();
    if (type === "danger") return new DangerButton();
    throw new Error("Unknown button type");
  }
}

// Client usage
const btn1 = ButtonFactory.create("default");
btn1.render(); // "Default button"

const btn2 = ButtonFactory.create("danger");
btn2.render(); // "Danger button"
```

#### Real-World Use Case

**Payment Gateway Example:**  
Your system needs to process different payment gateways—PayPal, Stripe, etc.—without knowing which at compile-time.

-   **Product** → `IPaymentGateway`
    
-   **ConcreteProduct** → `PayPalGateway`, `StripeGateway`
    
-   **Creator** → `PaymentGatewayFactory` (interface)
    
-   **ConcreteCreators** → `PayPalFactory`, `StripeFactory`
    
This leads to flexible, extensible gateway integration without modifying existing code (Open–Closed Principle).

### Builder Design Pattern

#### Intent

The **Builder Pattern** is used to **construct complex objects step by step**. Unlike the Factory or Abstract Factory patterns (which focus on object creation), Builder focuses on **how to assemble** an object.

-   It separates **object construction** from its **representation**, allowing the same construction process to create different representations.
    

> This is useful when creating objects with **many optional fields**, or objects that should be built in a particular sequence.

----------

#### When to Use

-   When you need to build **complex objects** that can't be created in a single step.
    
-   When you want to avoid telescoping constructors (constructors with too many parameters).
    
-   When the construction process involves multiple steps or configuration options.
    

Real-world examples:

-   Building a complex **house**, where you add walls, doors, windows separately.
    
-   Creating a **SQL query builder** step by step.
    
-   Setting up **HTTP requests** with optional headers, parameters, authentication, etc.

```
#include <iostream>
#include <string>

class Car {
private:
    std::string engine_;
    std::string wheels_;
    std::string color_;

public:
    void setEngine(const std::string& engine) { engine_ = engine; }
    void setWheels(const std::string& wheels) { wheels_ = wheels; }
    void setColor(const std::string& color) { color_ = color; }

    void specs() const {
        std::cout << "Engine: " << engine_
                  << ", Wheels: " << wheels_
                  << ", Color: " << color_ << std::endl;
    }
};

class CarBuilder {
private:
    std::unique_ptr<Car> car_;

public:
    CarBuilder() : car_(std::make_unique<Car>()) {}

    CarBuilder& setEngine(const std::string& engine) {
        car_->setEngine(engine);
        return *this;
    }

    CarBuilder& setWheels(const std::string& wheels) {
        car_->setWheels(wheels);
        return *this;
    }

    CarBuilder& setColor(const std::string& color) {
        car_->setColor(color);
        return *this;
    }

    std::unique_ptr<Car> build() {
        return std::move(car_);
    }
};

int main() {
    auto car = CarBuilder()
        .setEngine("V8 Turbo")
        .setWheels("18 inch Alloy")
        .setColor("Red")
        .build();

    car->specs();  // Output: Engine: V8 Turbo, Wheels: 18 inch Alloy, Color: Red

    return 0;
}
```

### Prototype Design Pattern

#### Intent

The **Prototype Pattern** is used when you want to **create new objects by copying existing ones**, rather than building from scratch (especially when object creation is expensive or complex).

In this pattern:

-   Instead of using a constructor, a new object is created by **cloning** an existing prototype object.
    
-   Each class implements a `clone()` method to copy itself.
    

----------

#### When to Use

-   When object creation is **costly** (due to resource-intensive setup).
    
-   When new objects should be **copies of existing ones**, possibly with slight modifications.
    
-   When you need to avoid subclassing purely to get different configurations of an object.
    

**Real-world Examples:**

-   Cloning documents, shapes, or GUI components.
    
-   Copying game entities (e.g., enemies, weapons) with base configurations.
    
-   When deserializing or duplicating objects in memory.

```
#include <iostream>
#include <memory>
#include <string>

// Prototype Interface
class Shape {
public:
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// Concrete Prototype: Circle
class Circle : public Shape {
    int radius_;
public:
    Circle(int radius) : radius_(radius) {}

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);  // Copy constructor
    }

    void draw() const override {
        std::cout << "Drawing Circle with radius " << radius_ << std::endl;
    }
};

// Concrete Prototype: Square
class Square : public Shape {
    int side_;
public:
    Square(int side) : side_(side) {}

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Square>(*this);  // Copy constructor
    }

    void draw() const override {
        std::cout << "Drawing Square with side " << side_ << std::endl;
    }
};

int main() {
    std::unique_ptr<Shape> original = std::make_unique<Circle>(10);
    std::unique_ptr<Shape> copy = original->clone();

    original->draw();  // Drawing Circle with radius 10
    copy->draw();      // Drawing Circle with radius 10

    return 0;
}
```

### Adapter Design Pattern

#### 1. Intent

The **Adapter Pattern** acts as a **bridge between two incompatible interfaces**. It allows classes with incompatible interfaces to work together without modifying their existing code.

In simple terms:

> **Adapter converts one interface into another.**

----------

#### 2. When to Use

-   You have existing classes that you want to reuse, but their interfaces are incompatible with the system.
    
-   You need to integrate legacy code with new systems without rewriting the legacy code.
    

----------

#### 3. Real-World Example

-   Think of a **power adapter**: You have a laptop charger designed for US plugs, but you're in Europe. Instead of changing the charger, you use a power adapter that allows the US plug to fit into European sockets.
    

In software:

-   Adapting a **third-party library API** to your existing code.
    
-   Converting **JSON data readers** to XML format consumers.

```
#include <iostream>
#include <string>

// Existing interface
class AudioPlayer {
public:
    void playMP3(const std::string& filename) {
        std::cout << "Playing MP3 file: " << filename << std::endl;
    }
};

// Incompatible interface
class AdvancedPlayer {
public:
    void playFLAC(const std::string& filename) {
        std::cout << "Playing FLAC file: " << filename << std::endl;
    }
};

// Adapter class
class PlayerAdapter : public AudioPlayer {
    AdvancedPlayer& advPlayer;
public:
    PlayerAdapter(AdvancedPlayer& player) : advPlayer(player) {}

    void playMP3(const std::string& filename) override {
        // Internally uses AdvancedPlayer to play FLAC
        std::cout << "[Adapter] Converting MP3 to FLAC...\n";
        advPlayer.playFLAC(filename);
    }
};

int main() {
    AdvancedPlayer flacPlayer;
    PlayerAdapter adapter(flacPlayer);

    adapter.playMP3("song.mp3");  // Uses AdvancedPlayer via adapter

    return 0;
}
```