const object = {
  "car" : {
    "wheels" : 1,
    "gears" : 0
  }
};

const path = "cars.gears";

let curr = {};
let s = "";
for(let i = 0; i < path.length;i++) {
  if(path[i] === ".") {
    curr = object[s];
    s = "";
    if(curr === undefined) {
      console.log("The item is not the dict")
      break;
    }
  } else {
    s += path[i];
  }
  console.log(curr);
}
if(curr[s] !== undefined) {
  console.log(curr[s]);
} else {
  console.log("No element found with the key")
}

