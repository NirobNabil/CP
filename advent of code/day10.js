let map = `
.#..#
.....
#####
....#
...##
`;

let lines = map.split(/\r\n|\r|\n/);
map = [];
let asteroids = [];

lines.forEach(function(line, iS){
  map.push([]);
  line.split("").forEach(function(point, iL){
    map[iS].push(point);
  })
})

map.shift();
map.pop();

map.forEach(function(line, iS){
  console.log(iS);
  console.log(line)
  line.forEach(function(point, iL){
    //console.log([iS, iL])
    //map[iS].push(point);
    if(point === "#"){
      let asteroidAt = [iS, iL];
      asteroids.push(asteroidAt);
    }
  })
})

function toDegree(radian){
  return (radian/Math.PI)*180
}

function getAngle(pointA, pointB, pointC){
  function pow(num, power){return Math.pow(num, power)}
  function getDistance(pointA, pointB){
    return Math.sqrt(pow(pointA[0]-pointB[0],2) + pow(pointA[1]-pointB[1], 2));
  }
  let a = getDistance(pointA, pointB);
  let b = getDistance(pointB, pointC);
  let c = getDistance(pointC, pointA);
  let res = toDegree(Math.acos( (pow(a,2) + pow(b,2) - pow(c,2) ) / (2*a*b) ) );

  let M = (pointC[1] - pointA[1])/(pointC[0] - pointA[0]);
  let C = pointC[1] - M*pointC[0];    // c = y2 - m*x2;

  function chooseAngle(angle){
    if( (M*pointB[0] - pointB[1] + C) > 0 ){
      console.log(`${pointC} - UP`);
      return 360 - angle;
    }else{
      console.log(`${pointC} - DOWN`);
      return angle;
    }
  }

  if( Math.ceil(res) - res < .000000000001 ){
    return chooseAngle(Math.ceil(res));
  }else if( res - Math.floor(res) < .000000000001 ){
    return chooseAngle(Math.floor(res));
  }else{
    return chooseAngle(res);
  }
}

function cmp(angle1, angle2){
  return Math.abs(angle1 - angle2) < .00000000001
}

function find(array, value, cmp){
  for(let i=0; i<array.length; i++){
    if(cmp(array[i], value)){
      return true
    }
  }
  return false;
}

let results = map;

asteroids.forEach(function(station, i){
  results[station[0]][station[1]] = 0;
  let angles = [];
  console.log(`for ${station[0]}, ${station[1]}`);
  asteroids.forEach(function(asteroid){
    let angle = getAngle([0,0], station, asteroid);
    if(asteroid[0] === station[0] && asteroid[1] == station[1]) return
    console.log(`${asteroid[0]},${asteroid[1]}  ${angle}  ${find(angles, angle, cmp )}`)
    if( !find(angles, angle, cmp) ){
      angles.push(angle);
      results[station[0]][station[1]]++;
      return;
    }
  })
})



console.log(asteroids);
console.log(results);

