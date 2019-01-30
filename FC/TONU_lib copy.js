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
        } else {
            el.className = el.className.replace(el_c, '');
        }
    },
    clearAll = function (els, els_c, t) {
        if (typeof els != 'object') {
            els = qA(els);
        }
        els.forEach(item => {
            clearIt(item, els_c, t);
        });
    },
    toggleIt = function (el, el_c) {
        var active = ' actst';
        if(el_c) {
            active = el_c;
        }
        if (el.className.indexOf(active) === -1) {
            el.className += active;
        } else {
            clearIt(el, active);
        }
    },
    closestEl = function (selector, el_data, evt) {
        var isIE = /* @cc_on!@ */false || !!document.documentMode,
            found = false;
        isIE ? target_el = evt.srcElement : target_el = evt.target;

        if (selector === '.') selector = 'class';
        else if (selector === '#') selector = 'id';
        while (!found && target_el !== null) {
            if (target_el.getAttribute(selector) !== null && target_el.getAttribute(selector).indexOf(el_data) !== -1) {
                found = true;
            } else {
                target_el = target_el.parentElement;
            }
        }
        return target_el;
    },
    qM = function (el) {
        var f = false;
        typeof el == 'object' ? el = el : el = q(el);
        o = {
            ne: el,
            c: el.className,
            i: el.id,
            nearest: function (p, b) {
                while (!f && el !== null) {
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