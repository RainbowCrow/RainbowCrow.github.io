size = 5;
color = "green";

class FreeHand {
    constructor(canvas) {
        this.canvas = canvas;
        this.context = canvas.getContext("2d");

        this.isDraw = false;
        this.points = [];// khai báo mảng points  

        this.context.lineJoin = 'round';
        this.context.lineCap = 'round';

        this.memCanvas = document.createElement('canvas');//tạo một canvas mới trên canvas cũ 
        this.memCanvas.width = canvas.width;
        this.memCanvas.height = canvas.height;
        this.memCtx = this.memCanvas.getContext('2d');
    }

    onmousedown(event) {
        this.x = event.offsetX;// lấy tọa độ x
        this.y = event.offsetY;// lấy tọa độ y 

        this.points.push({ // lưu x, y vào mảng point 
            x: this.x,
            y: this.y
        });

        this.isDraw = true;
        this.context.lineWidth = size; //độ rộng nét
        this.context.strokeStyle = color;//chọn màu 
    }

    onmousemove(event) {
        if (this.isDraw) {
            this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);//xóa 
            // put back the saved content                 35 + 37 ->> vẽ lại 1 cách nét hơn 
            this.context.drawImage(this.memCanvas, 0, 0);//vẽ lại những đường đã xóa 
            this.points.push({
                x: event.offsetX,
                y: event.offsetY
            });
            this.drawPoints();
        }
    }

    onmouseup(event) {
        if (this.isDraw) {
            this.isDraw = false;
            // When the pen is done, save the resulting context
            // to the in-memory canvas
            this.memCtx.clearRect(0, 0, this.canvas.width, this.canvas.height);
            this.memCtx.drawImage(this.canvas, 0, 0);
            this.points = [];
        }
    }

    drawPoints() {
        let ctx = this.context;

        if (this.points.length < 6) return;

        ctx.beginPath(), ctx.moveTo(this.points[0].x, this.points[0].y);
        let i;
        for (i = 1; i < this.points.length - 2; i++) {
            var c = (this.points[i].x + this.points[i + 1].x) / 2;
            var d = (this.points[i].y + this.points[i + 1].y) / 2;
            ctx.quadraticCurveTo(this.points[i].x, this.points[i].y, c, d);
        }
        ctx.quadraticCurveTo(this.points[i].x, this.points[i].y, this.points[i + 1].x, this.points[i + 1].y);
        ctx.stroke();
    }

    clearCanvas() {
        this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);
        this.memCtx.clearRect(0, 0, this.canvas.width, this.canvas.height);
    }
}


