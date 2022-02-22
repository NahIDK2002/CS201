struct ACE{
    short v;
    struct ACE *p;
};

short test(struct ACE *ptr){
    short ret=1;
    while (ptr){
        ret*=ptr->v;
        ptr=ptr->p;
    }
}