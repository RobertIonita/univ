window.onload = function () {
    var input = q('.base_input'),
        p = q('.base_input+p'),
        togglers = qA('.toggler');

    for (var i = 0; i < togglers.length; i++) {
        togglers[i].onclick = (e, i) => {
            clearIt(q('body'), ' actst');

            for (var i = 0; i < togglers.length; i++) {
                clearIt(togglers[i], ' actst');
                clearIt(qA('.contents')[i], ' actst');
            }
            toggleIt(e.target);
            var trigger = e.target.getAttribute('data-toggle');
            contents = q('.contents.' + trigger);
            toggleIt(contents);
            if(trigger != 'bases') {
                toggleIt(q('body'));
            }
        }
    }

    var switcher = q('.switcher div'),
        _s = 0;
    switcher.onclick = function () {
        toggleIt(this);
        _s = Number(!_s);
        _s ? formater = 3 : formater = 0;
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
        decimal = [0, 0],
        formater = 0,
        tr_arr = [];
    trFunc = function (f_t) {
        tr_arr = [];
        for (var i = 0; i < f_t.length; i++) {
            tr_arr.push((Number(f_t[i]) + formater).toString(2));
        }
        for (var i = 0; i < tr_arr.length; i++) {
            while (tr_arr[i].length < 4) {
                tr_arr[i] = '0' + tr_arr[i];
            }
        }
        return tr_arr.join().replace(/,/g, ' ');
    }
    transformIt = function (val, order) {
        decimal[0] = Number(inserts[0].value);
        decimal[1] = Number(inserts[1].value);
        outputs[order].innerHTML = trFunc(val);
        var result_of = decimal[0] + decimal[1];
        out_r.innerHTML = trFunc((result_of.toString()));
        inp_r.innerHTML = decimal[0] + decimal[1];
    }
    for (var i = 0; i < inserts.length; i++) {
        inserts[i].addEventListener('keyup', function () {
            var order = this.getAttribute('data-order'),
                val = this.value
            order = Number(order);
            val = val.split('');
            var k = 0;
            while (val[k] == '0') {
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
        xm = q('.Xm', mantisse),
        hexa = q('.hexa', mantisse),
        fulfilMantise = (k, m) => {
            xe.innerHTML = '';
            xm.innerHTML = '';
            for (var i = 0; i < k; i++) {
                xe.innerHTML += `<div class="d_fl a_c j_c">0</div>`
            }
            for (var i = 0; i < m; i++) {
                xm.innerHTML += `<div class="d_fl a_c j_c">0</div>`
            }
            var total = Number(m) + Number(k) + 1,
                quarters = Math.floor(total / 4),
                diff = total / 4 - quarters;
            xs.style.width = 'calc(100%/' + total + ')';
            xe.style.width = 'calc(100%*' + k + '/' + total + ')';
            xm.style.width = 'calc(100%*' + m + '/' + total + ')';
            hexa.innerHTML = '';
            if (diff) {
                hexa.innerHTML += '<div class="d_fl a_c j_c" style="width:calc(100%*' + 4 * diff + '/' + total + ')">0</div>';
            }
            for (var i = 0; i < quarters; i++) {
                hexa.innerHTML += '<div class="d_fl a_c j_c" style="width:calc(100%*' + 4 + '/' + total + ')">0</div>';
            }
        }
    var iee = q('.ieee754 input.main'),
        params = qA('.ieee754 [data-toggle]'),
        k = 8,
        mantisse_length = 23;
    fulfilMantise(k, mantisse_length);
    qA('.custom input').forEach(input => {
        input.onchange = function () {
            o = {
                k: this.getAttribute('data-for'),
                val: this.value
            }
            o.k ? k = o.val : mantisse_length = o.val;
            fulfilMantise(k, mantisse_length);
        }
    });
    params.forEach(element => {
        element.onclick = function () {
            clearAll(params, ' actst');
            toggleIt(element);
            var data = element.getAttribute('data-mantisse').split('-');
            k = data[0],
                mantisse_length = data[1];
            (k, mantisse_length);

            custom = q('.custom');
            if (element.getAttribute('data-toggle') == 'custom') {
                if (custom.className.indexOf('actst') == -1) {
                    custom.className += ' actst';
                }
            } else {
                clearIt(custom, ' actst');
            }
        }
    });
    var fulfilHexa = function() {
        var h_val = 0,
            hex_digits = qA('div', hexa),
            bin_digits = qA('div:not(.hexa)>div.a_c.j_c', mantisse);
        for (var i = bin_digits.length - 1; i >= 0; i--) {

            if ((i + 1) % 4 == 0) {
                h_val = 0;
                quart = 0;
            }
            if (Number(bin_digits[i].innerHTML)) {
                h_val += 2 ** quart;
            }
            hex_digits[Math.floor(i / 4)].innerHTML = h_val.toString(16).toUpperCase();
            quart++;
        }
    }
    iee.addEventListener('keyup', function () {
        var bias = 2 ** (k - 1) - 1,
            val = Number(this.value),
            b_val = val.toString(2).replace("-", ""),
            parts = b_val.split('.')[0].split(','),
            exponent = bias + parts[0].length - 1,
            xe_cell = qA('div', xe),
            xm_cell = qA('div', xm),
            b_exponent = exponent.toString(2),
            sign = q('.Xs div'),
            b_val = b_val.replace('.', '');
        o = {
            value: val,
            binary: b_val,
            parts: parts,
            exponent: exponent,
            bias: bias,
            b_exp: b_exponent
        }
        if (val >= 0) {
            sign.innerHTML = 0;
        } else {
            sign.innerHTML = 1;
        }

        for (var i = k - 1; i >= 0; i--) {
            xe_cell[i].innerHTML = b_exponent[b_exponent.length - k + i] || 0;
        }
        for (var i = 0; i < xm_cell.length; i++) {
            if (b_val[i + 1]) {
                xm_cell[i].innerHTML = b_val[i + 1];
            } else {
                xm_cell[i].innerHTML = 0;
            }
        }
        q('#Xe').innerHTML = exponent + '<sub>10</sub> = ' + b_exponent + '<sub>2</sub>';
        q('#bias').innerHTML = bias;
        var hidden,
            mant;
        if (b_val != 0 && (b_val != 1 || b_val.length != 1)) {
            hidden = b_val[0] + ',';
            mant = b_val.slice(1);
        } else if (b_val == 1) {
            hidden = '';
            mant = 1;
        } else {
            hidden = '';
            mant = 0;
        }
        q('#Xm').innerHTML = hidden + '' + mant;
        fulfilHexa();
    });
}