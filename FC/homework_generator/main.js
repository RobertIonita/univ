window.onload = function () {

    var list = qA(".students ul li"),
        items = q(".items"),
        i = 0,
        ol;
    list.forEach(element => {
        items.innerHTML += `
            <div class="item">
                <p>Nume și Prenume: <b>${element.innerHTML}</b></p>
                <p>Efectuați adunarea în BCD și E3 a numerelor ce urmează:</p>
                <ol type="a">
                </ol >
            </div >
        `
        ol = q("ol", qA(".item")[i]);
        var arr1 = [],
            arr2 = [],
            populate = (array) => {
                while (array.length < 6) {
                    var r = Math.floor(Math.random() * 10000) + 1;
                    if (r < 1000) r += 1000;
                    array.push(r);
                }
            };
        populate(arr1);
        populate(arr2);
        for (let j = 0; j < 6; j++) {
            ol.innerHTML += `<li>${arr1[j]} + ${arr2[j]}</li>`
        }
        i++;
    });
}