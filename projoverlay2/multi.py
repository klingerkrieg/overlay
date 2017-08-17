def multi(a,b):
    import sys
    sys.argv = ["fnome"]
    import Tkinter
    label = Tkinter.Label(text='Text on the screen', font=('Times','30'), fg='orange', bg='white')
    label.master.overrideredirect(True)
    label.master.geometry("+250+250")
    label.master.lift()
    label.master.wm_attributes("-topmost", True)
    label.master.wm_attributes("-disabled", True)
    label.master.wm_attributes("-transparentcolor", "white")
    label.pack()
    label.mainloop()


    
    print "Will compute", a, "times", b
    c = 0
    for i in range(0, a):
        c = c + b
    return c
