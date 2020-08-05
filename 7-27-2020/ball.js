class Ball {
    constructor(x, y, r, color) {
        this.x = x;
        this.y = y;
        this.r = r;
        this.color = color;
    }

    draw() {
        ctx.beginPath();
        ctx.shadowColor = 'white';
        ctx.shadowBlur = this.r * 0.1;
        ctx.fill();
        ctx.arc(this.x, this.y, this.r, 0, Math.PI * 2, false);
        ctx.fillStyle = this.color;
        ctx.fill();
        ctx.stroke();
    }
}

class Boss extends Ball {
    constructor(x, y, r, color, name, score) {
        super(x, y, r, color);
        this.name = name;
        this.score = score;
    }

    drawBoss() {
        this.draw();
        ctx.fillStyle = 'white';
        ctx.font = "20px Arial";
        ctx.textAlign = 'center';
        ctx.textBaseline = 'middle';
        ctx.fillText(this.name, this.x, this.y);
    }

    drawScore() {
        ctx.fillStyle = 'white';
        ctx.font = "20px Arial";
        ctx.textAlign = 'center';
        ctx.textBaseline = 'middle';
        ctx.fillText(this.score, canvas.width * 0.025, canvas.height * 0.95);
    }

    move() {
        if (boss.x < boss.r) boss.x = boss.r;
        if (boss.y < boss.r) boss.y = boss.r;
        if (boss.x > canvas.width - boss.r) boss.x = canvas.width - boss.r;
        if (boss.y > canvas.height - boss.r) boss.y = canvas.height - boss.r;
        this.drawBoss();
        this.drawScore();
    }

    eatMinion() {
        this.score += 1;
        if (this.score % 10 == 0 ) this.r += 10;
    }
}