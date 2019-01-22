var d = document,
    q = function (sel, target) {
        if (target === undefined) target = d;
        return target.querySelector(sel);
    },
    qA = function (sel, target) {
        if (target === undefined) target = d;
        return target.querySelectorAll(sel);
    },
    clearIt = (el, el_c, t) => {
        if (t) {
            el.className = el_c;
        } else{
            el.className = el.className.replace(el_c, '');
        }
    },
    toggleIt = function (el, event) {
        if (el.className.indexOf('actst') === -1) {
            el.className += ' actst'
        } else {
            clearIt(el, ' actst');
        }
    },
    closestEls = function (selector, el_name, evt) {
        var target_el = evt.target,
            found = false;
        if (selector === '.') selector = 'class';
        else if (selector === '#') selector = 'id';
        while (found === false && target_el !== null) {
            if (target_el.getAttribute(selector) !== null && target_el.getAttribute(selector).indexOf(el_name) !== -1) {
                found = true;
            } else {
                target_el = target_el.parentElement;
            }
        }
        return target_el;
    },
    qM = function (el, n) {
        var f = false;
        n ? el = el : el = q(el);
        o = {
            ne: el,
            c: el.className,
            i: el.id,
            nearest: function (p, b) {
                while (f === false && el !== null) {
                    b ? t = el.id : t = el.className;
                    if (t.indexOf(p) !== -1) {
                        f = true;
                    } else {
                        el = el.parentElement;
                        t = el;
                    }
                }
                return el;
            }
        }
        return o;
    };
window.onload = function () {

    var input = q('.base_input'),
        p = q('.base_input+p'),
        togglers = qA('.toggler');
    
    for (var i = 0; i < togglers.length; i++) {
        togglers[i].onclick = (e, i) => {
            for (var i = 0; i < togglers.length; i++) {
                clearIt(togglers[i], ' actst');
                clearIt(qA('.contents')[i], ' actst');
            }
            toggleIt(e.target);
            var trigger = e.target.getAttribute('data-toggle');
                contents = q('.contents.'+trigger);
            toggleIt(contents, 'actst');
        }
    }

    var switcher = q('.switcher div'),
        _s = 0;
    switcher.onclick = function() {
        toggleIt(this);
        _s = Number(!_s);
        _s?formater=3:formater=0;
    }

    input.addEventListener('keyup', function () {
        var val = Number(input.value);

        p.innerHTML = 'Base 2: \
            ' + val.toString(2) + '\
            <br/> Base 16: \
            ' + val.toString(16) + '\
            <br/> Base 8: \
            ' + val.toString(8);
    });

    var inserts = qA('.inserts input'),
        outputs = qA('.outputs span'),
        out_r = q('.outputs p'),
        inp_r = q('.inserts p'),
        decimal = [0,0],
        formater = 0,
        tr_arr = [];
        trFunc = function (f_t) {
            tr_arr = [];
            for (var i=0; i<f_t.length; i++) {
                tr_arr.push((Number(f_t[i])+formater).toString(2));
            }
            for (var i=0; i<tr_arr.length; i++) {
                while (tr_arr[i].length < 4) {
                    tr_arr[i] = '0'+tr_arr[i];
                }
            }
            return tr_arr.join().replace(/,/g, ' ');
        }
        transformIt = function(val, order) {
            decimal[0] = Number(inserts[0].value);
            decimal[1] = Number(inserts[1].value);
            outputs[order].innerHTML = trFunc(val);
            var result_of = decimal[0]+decimal[1];
            out_r.innerHTML = trFunc((result_of.toString()));
            inp_r.innerHTML = decimal[0]+decimal[1];
        }
    for (var i=0; i<inserts.length; i++) {
        inserts[i].addEventListener('keyup', function() {
            var order = this.getAttribute('data-order'),
                val = this.value
            order = Number(order);
            val = val.split('');
            var k = 0;
            while (val[k] == '0'){
                val[k] = '';
                k++;
            }
            val = val.join().replace(/,/g, '');
            transformIt(val, order);
        });
    }
    var mantisse = q('.mantisse'),
        xs = q('.Xs', mantisse),
        xe = q('.Xe', mantisse),
        xm = q('.Xm', mantisse);
    for (var i=0; i<8; i++) {
        xe.innerHTML += `<div class="d_fl a_c j_c">0</div>`
    }
    for (var i=0; i<23; i++) {
        xm.innerHTML += `<div class="d_fl a_c j_c">0</div>`
    }
    var iee = q('.ieee754 input');
    iee.addEventListener('keyup', function() {
        var v = [this.value, 0],
            s = 1,
            x_e = 0,
            len,
            p = v[0].split(',')[0].split('.')[0];
        v[0]>0?s=1:s=0;
        xs.firstElementChild.innerHTML = s;
        v[0] = p;
        v[1] = Number(this.value) - Number(p);
        console.log(v[1])
        len = (Number(v[0]).toString(2)).length;
        x_e = (len+126).toString(2);
        for(var i=0; i<x_e.length; i++) {
            qA('.Xe div')[i].innerHTML = x_e[i];
        }
        v[1] = p.toString(2);
        for(var i=0; i<v[1].length; i++) {
            qA('.Xm div')[i].innerHTML = v[1][i];
        }
        
    });
}