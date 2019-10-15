window.onload = function () {

    var list = qA(".students ul li"),
        items = q(".items"),
        i = 0,
        ol;
    list.forEach(element => {
        items.innerHTML += `
            <div class="item">
                <p>Nume și Prenume: <b>${element.innerHTML}</b></p>
                <p>1)Transformați următoarele numere din baza 10 în baza 2 și în baza 16:</p>
                <ol type="a">
                </ol >
                <p>2)Transformați următoarele numere din baza 16 în baza 2:</p>
                <ol type="a">
                </ol>
            </div >
        `
        ol = q("ol", qA(".item")[i]);
        var arr = [],
            floats = [0.5, 0.25, 0.75, 0.125, 0.625, 0.1875, 0.875, 0.375, 0.3125, 0.0625];
        while (arr.length < 10) {
            var r = Math.floor(Math.random() * 100) + 20;
            if (arr.indexOf(r) === -1) arr.push(r);
        }
        for (let j = 0; j < 10; j++) {
            float = floats[Math.floor(Math.random() * 10)];
            ol.innerHTML += `<li>${arr[j] + float}</li>`
        }
        ol = qA("ol", qA(".item")[i])[1];
        arr = [];
        while (arr.length < 10) {
            var r = Math.floor(Math.random() * 100) + 20;
            if (arr.indexOf(r) === -1) arr.push(r);
        }
        for (let j = 0; j < 10; j++) {
            float = floats[Math.floor(Math.random() * 10)];
            ol.innerHTML += `<li>${(arr[j] + float).toString(16).toUpperCase()}</li>`
        }
        i++;
    });
}