const canvas = document.getElementById("canvas");
const ctx = canvas.getContext('2d');

canvas.width = innerWidth - 10;
canvas.height = innerHeight - 20;

const N = 50;

function random(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

addEventListener("keydown", function (e) {
    if (e.keyCode == 37) {
        if (boss.x == boss.r) return;
        boss.x -= 10;
    }
    if (e.keyCode == 38) {
        if (boss.y == boss.r) return;
        boss.y -= 10;
    }
    if (e.keyCode == 39) {
        if (boss.x == canvas.width - boss.r) return;
        boss.x += 10;
    }
    if (e.keyCode == 40) {
        if (boss.x == canvas.height - boss.r) return;
        boss.y += 10;
    }
});

function eat_minion() {
    minions.forEach(minion => {
        if (Math.sqrt(Math.pow(boss.x - minion.x, 2) + Math.pow(boss.y - minion.y, 2)) < (boss.r + minion.r)) {
            minions.splice(minions.indexOf(minion), 1);
            boss.eatMinion();
        }
    });

}

let boss = new Boss(40, 40, 40, "yellow", 'Boss', 0);

let minions = [];
for (var i = 0; i < N; i++) {
    minions.push(new Ball(random(0 + 10, canvas.width - 10), random(90, canvas.height - 10), 10, 'red'));
}

document.getElementById('start-game').onclick = () => {
    document.getElementById('start').style.display = 'none';
    animate();
}

document.getElementById('restart-game').onclick = () => {
    document.getElementById('finish').style.display = 'none';
    canvas.style.opacity = '1';
    create_elements();
    animate();
}


function create_elements() {
    boss.score = 0;
    boss.x = boss.y = boss.r = 40; 
    for (var i = 0; i < N; i++) {
        minions.push(new Ball(random(0 + 10, canvas.width - 10), random(90, canvas.height - 10), 10, 'red'));
    }
}

function animate() {
    var action = requestAnimationFrame(animate);
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    boss.move();
    minions.forEach(minion => {
        minion.draw();
    });
    if (boss.score == N) {
        cancelAnimationFrame(action);
        canvas.style.opacity = '0.5';
        document.getElementById('finish').style.display = 'inline-block';
    }
    eat_minion();
}



