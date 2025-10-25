class MyClass {
  #x = 0;     // To define private variables in javascript use # to represent it .
              // There is no accesss modifier like private.
  add(val) {
    this.#x += val;
  }
  getX() {
    return this.#x;
  }
}

let c = new MyClass();
console.log(c.getX()); // 0
c.add(10);
console.log(c.getX());
let c1 = new MyClass();
c1.add(20)
console.log(c1.getX());
c = c1
console.log(c.getX());
