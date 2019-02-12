# univ
Repo for university

---------------------------------------------------------------------------------------------------

IPC - prictice files with structs
    You have some useful commands that I wrote for you in .vscode folder. DO NOT TOUCH IT! :
        Alt+F9 will trigger task "Compiles C file"
        Ctrl+F9 will trigger task "Run C file"
        By "C file" is understood file that is currently focused in workspace 
        (exemple: now README.md is focused)
---------------------------------------------------------------------------------------------------

FC - problem solver
    You can use it to check answers on your homework
    For portability reasons, this project is build with plain JS/CSS/HTML
    DON'T U DARE to call it grandma's technology!

---------------------------------------------------------------------------------------------------

TONU_lib.js

        q(sel, target) -
                This function comes in handly to get an element by classname, id 
                or even a custom attribute. It searches in your target by selector 'sel', if you
                want to find node in this way.
                'el_name' is tricky, be carefull 
                'target' is not set, it would search in entire document.

        qA(sel, target) -
                It is an extended use of q(sel, target), that returns instead of first match, all 
                nodes in the target parent.

        clearIt(el, el_c, t) -
                Nice function that helps to keep code clean and more readable. It simply removes 
                all classes that element 'el' has and sets its classname to desired new one - 'el_c'
                Otherwise if 't' param is not given function wolud invert its behavior - 
                all classes except 'el_c' will be kept.

        clearAll(els, els_c, t) -
                As well as qA it does simply work for all nodes that match requirements.
                As a new feature, clearAll accepts element 'el' as a nodelist and also as a string 
                that is classname for those nodelist.
        
        toggleIt(el, el_c) -
                Best friend when it comes to builing togglers/switches etc.
                If classname to toggle 'el_c' is not set, it would take the default 'actst'.
                Next it will check to se if rather element 'el' does have class 'el_c' and work by
                suiting scenario.

        closestEl(selector, el_name, evt) -
                Powerfull tool that hepls to avoid creating lots of event listeners. A frequent use
                is binding the 'evt' event to a common parent and by using node that triggered the
                event you can easily search upside-down in the node tree and return the desired one.
                As a selector you can use everything. If you want to search by classname then set
                'selector' param to '.', for id to '#' or whatever your data attribute is if you
                want to find node in this way.
                Argument 'el_data' is what are you looking for.
                (ex: closestEl('.', 'banana', e) will return first node that has classname banana.
                where 'e' is the event that triggered the call. DO NOT assign it to anyting)

        qM(el).nearest(p,b) -
                closestEl is great, but what if no event can be binded ? This is where this shinny
                method comes in. Note that qM stands for query-Method.
                Use its method 'nearest(p, b)' and do not try to understand how it works, call it
                magic, simply know that if param 'b' is set, it searches by id instead of classname.
                Argument 'el' is node that is looked for, it can be a string or even a object.
                It works pretty much like in clearAll(els, els_c, t) 'els' does.
                (ex: qM('.monkey').nearest('banana') will return the nearest node, which classname
                is 'banana', to initial node with classname 'monkey'.
                In other words: it would bring the nearest banana to monkey).
