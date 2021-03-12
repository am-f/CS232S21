
msb:     file format elf64-x86-64


Disassembly of section .init:

0000000000000560 <_init>:
_init():
 560:	48 83 ec 08          	sub    $0x8,%rsp
 564:	48 8b 05 7d 0a 20 00 	mov    0x200a7d(%rip),%rax        # 200fe8 <__gmon_start__>
 56b:	48 85 c0             	test   %rax,%rax
 56e:	74 02                	je     572 <_init+0x12>
 570:	ff d0                	callq  *%rax
 572:	48 83 c4 08          	add    $0x8,%rsp
 576:	c3                   	retq   

Disassembly of section .plt:

0000000000000580 <.plt>:
 580:	ff 35 2a 0a 20 00    	pushq  0x200a2a(%rip)        # 200fb0 <_GLOBAL_OFFSET_TABLE_+0x8>
 586:	ff 25 2c 0a 20 00    	jmpq   *0x200a2c(%rip)        # 200fb8 <_GLOBAL_OFFSET_TABLE_+0x10>
 58c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000590 <putchar@plt>:
 590:	ff 25 2a 0a 20 00    	jmpq   *0x200a2a(%rip)        # 200fc0 <putchar@GLIBC_2.2.5>
 596:	68 00 00 00 00       	pushq  $0x0
 59b:	e9 e0 ff ff ff       	jmpq   580 <.plt>

00000000000005a0 <printf@plt>:
 5a0:	ff 25 22 0a 20 00    	jmpq   *0x200a22(%rip)        # 200fc8 <printf@GLIBC_2.2.5>
 5a6:	68 01 00 00 00       	pushq  $0x1
 5ab:	e9 d0 ff ff ff       	jmpq   580 <.plt>

00000000000005b0 <atoi@plt>:
 5b0:	ff 25 1a 0a 20 00    	jmpq   *0x200a1a(%rip)        # 200fd0 <atoi@GLIBC_2.2.5>
 5b6:	68 02 00 00 00       	pushq  $0x2
 5bb:	e9 c0 ff ff ff       	jmpq   580 <.plt>

Disassembly of section .plt.got:

00000000000005c0 <__cxa_finalize@plt>:
 5c0:	ff 25 32 0a 20 00    	jmpq   *0x200a32(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 5c6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000000005d0 <_start>:
_start():
 5d0:	31 ed                	xor    %ebp,%ebp
 5d2:	49 89 d1             	mov    %rdx,%r9
 5d5:	5e                   	pop    %rsi
 5d6:	48 89 e2             	mov    %rsp,%rdx
 5d9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
 5dd:	50                   	push   %rax
 5de:	54                   	push   %rsp
 5df:	4c 8d 05 1a 03 00 00 	lea    0x31a(%rip),%r8        # 900 <__libc_csu_fini>
 5e6:	48 8d 0d a3 02 00 00 	lea    0x2a3(%rip),%rcx        # 890 <__libc_csu_init>
 5ed:	48 8d 3d e6 00 00 00 	lea    0xe6(%rip),%rdi        # 6da <main>
 5f4:	ff 15 e6 09 20 00    	callq  *0x2009e6(%rip)        # 200fe0 <__libc_start_main@GLIBC_2.2.5>
 5fa:	f4                   	hlt    
 5fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000000600 <deregister_tm_clones>:
deregister_tm_clones():
 600:	48 8d 3d 09 0a 20 00 	lea    0x200a09(%rip),%rdi        # 201010 <__TMC_END__>
 607:	55                   	push   %rbp
 608:	48 8d 05 01 0a 20 00 	lea    0x200a01(%rip),%rax        # 201010 <__TMC_END__>
 60f:	48 39 f8             	cmp    %rdi,%rax
 612:	48 89 e5             	mov    %rsp,%rbp
 615:	74 19                	je     630 <deregister_tm_clones+0x30>
 617:	48 8b 05 ba 09 20 00 	mov    0x2009ba(%rip),%rax        # 200fd8 <_ITM_deregisterTMCloneTable>
 61e:	48 85 c0             	test   %rax,%rax
 621:	74 0d                	je     630 <deregister_tm_clones+0x30>
 623:	5d                   	pop    %rbp
 624:	ff e0                	jmpq   *%rax
 626:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 62d:	00 00 00 
 630:	5d                   	pop    %rbp
 631:	c3                   	retq   
 632:	0f 1f 40 00          	nopl   0x0(%rax)
 636:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 63d:	00 00 00 

0000000000000640 <register_tm_clones>:
register_tm_clones():
 640:	48 8d 3d c9 09 20 00 	lea    0x2009c9(%rip),%rdi        # 201010 <__TMC_END__>
 647:	48 8d 35 c2 09 20 00 	lea    0x2009c2(%rip),%rsi        # 201010 <__TMC_END__>
 64e:	55                   	push   %rbp
 64f:	48 29 fe             	sub    %rdi,%rsi
 652:	48 89 e5             	mov    %rsp,%rbp
 655:	48 c1 fe 03          	sar    $0x3,%rsi
 659:	48 89 f0             	mov    %rsi,%rax
 65c:	48 c1 e8 3f          	shr    $0x3f,%rax
 660:	48 01 c6             	add    %rax,%rsi
 663:	48 d1 fe             	sar    %rsi
 666:	74 18                	je     680 <register_tm_clones+0x40>
 668:	48 8b 05 81 09 20 00 	mov    0x200981(%rip),%rax        # 200ff0 <_ITM_registerTMCloneTable>
 66f:	48 85 c0             	test   %rax,%rax
 672:	74 0c                	je     680 <register_tm_clones+0x40>
 674:	5d                   	pop    %rbp
 675:	ff e0                	jmpq   *%rax
 677:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 67e:	00 00 
 680:	5d                   	pop    %rbp
 681:	c3                   	retq   
 682:	0f 1f 40 00          	nopl   0x0(%rax)
 686:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 68d:	00 00 00 

0000000000000690 <__do_global_dtors_aux>:
__do_global_dtors_aux():
 690:	80 3d 79 09 20 00 00 	cmpb   $0x0,0x200979(%rip)        # 201010 <__TMC_END__>
 697:	75 2f                	jne    6c8 <__do_global_dtors_aux+0x38>
 699:	48 83 3d 57 09 20 00 	cmpq   $0x0,0x200957(%rip)        # 200ff8 <__cxa_finalize@GLIBC_2.2.5>
 6a0:	00 
 6a1:	55                   	push   %rbp
 6a2:	48 89 e5             	mov    %rsp,%rbp
 6a5:	74 0c                	je     6b3 <__do_global_dtors_aux+0x23>
 6a7:	48 8b 3d 5a 09 20 00 	mov    0x20095a(%rip),%rdi        # 201008 <__dso_handle>
 6ae:	e8 0d ff ff ff       	callq  5c0 <__cxa_finalize@plt>
 6b3:	e8 48 ff ff ff       	callq  600 <deregister_tm_clones>
 6b8:	c6 05 51 09 20 00 01 	movb   $0x1,0x200951(%rip)        # 201010 <__TMC_END__>
 6bf:	5d                   	pop    %rbp
 6c0:	c3                   	retq   
 6c1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 6c8:	f3 c3                	repz retq 
 6ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000006d0 <frame_dummy>:
frame_dummy():
 6d0:	55                   	push   %rbp
 6d1:	48 89 e5             	mov    %rsp,%rbp
 6d4:	5d                   	pop    %rbp
 6d5:	e9 66 ff ff ff       	jmpq   640 <register_tm_clones>

00000000000006da <main>:
main():
/home/runner/Assignments/bonus_assign/task1/msb.c:9
int msb(int x);
void print_binary(int n);

//Please do not modify main().
//All your changes must be made within msb()
int main(int argc, char **argv) {
 6da:	55                   	push   %rbp
 6db:	48 89 e5             	mov    %rsp,%rbp
 6de:	48 83 ec 20          	sub    $0x20,%rsp
 6e2:	89 7d ec             	mov    %edi,-0x14(%rbp)
 6e5:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:10
	if (argc<2) {
 6e9:	83 7d ec 01          	cmpl   $0x1,-0x14(%rbp)
 6ed:	7f 22                	jg     711 <main+0x37>
/home/runner/Assignments/bonus_assign/task1/msb.c:11
		printf("Invoke as %s <n> \n\twhere <n> is an integer\n",argv[0]);
 6ef:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 6f3:	48 8b 00             	mov    (%rax),%rax
 6f6:	48 89 c6             	mov    %rax,%rsi
 6f9:	48 8d 3d 18 02 00 00 	lea    0x218(%rip),%rdi        # 918 <_IO_stdin_used+0x8>
 700:	b8 00 00 00 00       	mov    $0x0,%eax
 705:	e8 96 fe ff ff       	callq  5a0 <printf@plt>
/home/runner/Assignments/bonus_assign/task1/msb.c:12
		return 1;
 70a:	b8 01 00 00 00       	mov    $0x1,%eax
 70f:	eb 62                	jmp    773 <main+0x99>
/home/runner/Assignments/bonus_assign/task1/msb.c:14
	}
	int x=atoi(argv[1]);
 711:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 715:	48 83 c0 08          	add    $0x8,%rax
 719:	48 8b 00             	mov    (%rax),%rax
 71c:	48 89 c7             	mov    %rax,%rdi
 71f:	e8 8c fe ff ff       	callq  5b0 <atoi@plt>
 724:	89 45 fc             	mov    %eax,-0x4(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:15
	printf("X= "); 
 727:	48 8d 3d 16 02 00 00 	lea    0x216(%rip),%rdi        # 944 <_IO_stdin_used+0x34>
 72e:	b8 00 00 00 00       	mov    $0x0,%eax
 733:	e8 68 fe ff ff       	callq  5a0 <printf@plt>
/home/runner/Assignments/bonus_assign/task1/msb.c:16
	print_binary(x); 
 738:	8b 45 fc             	mov    -0x4(%rbp),%eax
 73b:	89 c7                	mov    %eax,%edi
 73d:	e8 f1 00 00 00       	callq  833 <print_binary>
/home/runner/Assignments/bonus_assign/task1/msb.c:17
	printf("\n");
 742:	bf 0a 00 00 00       	mov    $0xa,%edi
 747:	e8 44 fe ff ff       	callq  590 <putchar@plt>
/home/runner/Assignments/bonus_assign/task1/msb.c:18
	printf("The most significant bit of %d is at position %d\n",x,msb(x));
 74c:	8b 45 fc             	mov    -0x4(%rbp),%eax
 74f:	89 c7                	mov    %eax,%edi
 751:	e8 1f 00 00 00       	callq  775 <msb>
 756:	89 c2                	mov    %eax,%edx
 758:	8b 45 fc             	mov    -0x4(%rbp),%eax
 75b:	89 c6                	mov    %eax,%esi
 75d:	48 8d 3d e4 01 00 00 	lea    0x1e4(%rip),%rdi        # 948 <_IO_stdin_used+0x38>
 764:	b8 00 00 00 00       	mov    $0x0,%eax
 769:	e8 32 fe ff ff       	callq  5a0 <printf@plt>
/home/runner/Assignments/bonus_assign/task1/msb.c:19
	return 0;
 76e:	b8 00 00 00 00       	mov    $0x0,%eax
/home/runner/Assignments/bonus_assign/task1/msb.c:20
}
 773:	c9                   	leaveq 
 774:	c3                   	retq   

0000000000000775 <msb>:
msb():
/home/runner/Assignments/bonus_assign/task1/msb.c:22

int msb(int x) {
 775:	55                   	push   %rbp
 776:	48 89 e5             	mov    %rsp,%rbp
 779:	48 83 ec 30          	sub    $0x30,%rsp
 77d:	89 7d dc             	mov    %edi,-0x24(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:23
	if (x==0) return -1;                  
 780:	83 7d dc 00          	cmpl   $0x0,-0x24(%rbp)
 784:	75 0a                	jne    790 <msb+0x1b>
/home/runner/Assignments/bonus_assign/task1/msb.c:23 (discriminator 1)
 786:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 78b:	e9 a1 00 00 00       	jmpq   831 <msb+0xbc>
/home/runner/Assignments/bonus_assign/task1/msb.c:25
	int w, ep, hw;
	w=32;
 790:	c7 45 f0 20 00 00 00 	movl   $0x20,-0x10(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:26
	ep=0;
 797:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:27
  hw = w;
 79e:	8b 45 f0             	mov    -0x10(%rbp),%eax
 7a1:	89 45 ec             	mov    %eax,-0x14(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:28
	while(hw > 1) {
 7a4:	eb 7e                	jmp    824 <msb+0xaf>
/home/runner/Assignments/bonus_assign/task1/msb.c:29
    hw = hw/2;
 7a6:	8b 45 ec             	mov    -0x14(%rbp),%eax
 7a9:	89 c2                	mov    %eax,%edx
 7ab:	c1 ea 1f             	shr    $0x1f,%edx
 7ae:	01 d0                	add    %edx,%eax
 7b0:	d1 f8                	sar    %eax
 7b2:	89 45 ec             	mov    %eax,-0x14(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:30
    unsigned int maskBase = 0xffffffff;
 7b5:	c7 45 f4 ff ff ff ff 	movl   $0xffffffff,-0xc(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:31
    unsigned int mask = maskBase>>(w-hw);
 7bc:	8b 45 f0             	mov    -0x10(%rbp),%eax
 7bf:	2b 45 ec             	sub    -0x14(%rbp),%eax
 7c2:	8b 55 f4             	mov    -0xc(%rbp),%edx
 7c5:	89 c1                	mov    %eax,%ecx
 7c7:	d3 ea                	shr    %cl,%edx
 7c9:	89 d0                	mov    %edx,%eax
 7cb:	89 45 f8             	mov    %eax,-0x8(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:32
    mask = mask<<(hw+ep);
 7ce:	8b 55 ec             	mov    -0x14(%rbp),%edx
 7d1:	8b 45 e8             	mov    -0x18(%rbp),%eax
 7d4:	01 d0                	add    %edx,%eax
 7d6:	89 c1                	mov    %eax,%ecx
 7d8:	d3 65 f8             	shll   %cl,-0x8(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:33
		printf("M= "); print_binary(mask); printf(" hw=%d ep=%d\n",hw,ep);
 7db:	48 8d 3d 98 01 00 00 	lea    0x198(%rip),%rdi        # 97a <_IO_stdin_used+0x6a>
 7e2:	b8 00 00 00 00       	mov    $0x0,%eax
 7e7:	e8 b4 fd ff ff       	callq  5a0 <printf@plt>
 7ec:	8b 45 f8             	mov    -0x8(%rbp),%eax
 7ef:	89 c7                	mov    %eax,%edi
 7f1:	e8 3d 00 00 00       	callq  833 <print_binary>
 7f6:	8b 55 e8             	mov    -0x18(%rbp),%edx
 7f9:	8b 45 ec             	mov    -0x14(%rbp),%eax
 7fc:	89 c6                	mov    %eax,%esi
 7fe:	48 8d 3d 79 01 00 00 	lea    0x179(%rip),%rdi        # 97e <_IO_stdin_used+0x6e>
 805:	b8 00 00 00 00       	mov    $0x0,%eax
 80a:	e8 91 fd ff ff       	callq  5a0 <printf@plt>
/home/runner/Assignments/bonus_assign/task1/msb.c:34
    unsigned int xHalf = x & mask;
 80f:	8b 45 dc             	mov    -0x24(%rbp),%eax
 812:	23 45 f8             	and    -0x8(%rbp),%eax
 815:	89 45 fc             	mov    %eax,-0x4(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:35
    if(xHalf > 0) {
 818:	83 7d fc 00          	cmpl   $0x0,-0x4(%rbp)
 81c:	74 06                	je     824 <msb+0xaf>
/home/runner/Assignments/bonus_assign/task1/msb.c:36
      ep = ep + hw;
 81e:	8b 45 ec             	mov    -0x14(%rbp),%eax
 821:	01 45 e8             	add    %eax,-0x18(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:28
	while(hw > 1) {
 824:	83 7d ec 01          	cmpl   $0x1,-0x14(%rbp)
 828:	0f 8f 78 ff ff ff    	jg     7a6 <msb+0x31>
/home/runner/Assignments/bonus_assign/task1/msb.c:39
    }
	}
	return ep;
 82e:	8b 45 e8             	mov    -0x18(%rbp),%eax
/home/runner/Assignments/bonus_assign/task1/msb.c:40
}
 831:	c9                   	leaveq 
 832:	c3                   	retq   

0000000000000833 <print_binary>:
print_binary():
/home/runner/Assignments/bonus_assign/task1/msb.c:43

//Do not modify print_binary
void print_binary(int n) {
 833:	55                   	push   %rbp
 834:	48 89 e5             	mov    %rsp,%rbp
 837:	48 83 ec 20          	sub    $0x20,%rsp
 83b:	89 7d ec             	mov    %edi,-0x14(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:45
	int i;
	for(i=31;i>=0;i--) {
 83e:	c7 45 fc 1f 00 00 00 	movl   $0x1f,-0x4(%rbp)
 845:	eb 3e                	jmp    885 <print_binary+0x52>
/home/runner/Assignments/bonus_assign/task1/msb.c:46
		printf("%c",(n&1<<i)?'1':'0');
 847:	8b 45 fc             	mov    -0x4(%rbp),%eax
 84a:	8b 55 ec             	mov    -0x14(%rbp),%edx
 84d:	89 c1                	mov    %eax,%ecx
 84f:	d3 fa                	sar    %cl,%edx
 851:	89 d0                	mov    %edx,%eax
 853:	83 e0 01             	and    $0x1,%eax
 856:	85 c0                	test   %eax,%eax
 858:	74 07                	je     861 <print_binary+0x2e>
/home/runner/Assignments/bonus_assign/task1/msb.c:46 (discriminator 1)
 85a:	b8 31 00 00 00       	mov    $0x31,%eax
 85f:	eb 05                	jmp    866 <print_binary+0x33>
/home/runner/Assignments/bonus_assign/task1/msb.c:46 (discriminator 2)
 861:	b8 30 00 00 00       	mov    $0x30,%eax
/home/runner/Assignments/bonus_assign/task1/msb.c:46 (discriminator 4)
 866:	89 c7                	mov    %eax,%edi
 868:	e8 23 fd ff ff       	callq  590 <putchar@plt>
/home/runner/Assignments/bonus_assign/task1/msb.c:47 (discriminator 4)
		if (0==i%4) printf(" ");
 86d:	8b 45 fc             	mov    -0x4(%rbp),%eax
 870:	83 e0 03             	and    $0x3,%eax
 873:	85 c0                	test   %eax,%eax
 875:	75 0a                	jne    881 <print_binary+0x4e>
/home/runner/Assignments/bonus_assign/task1/msb.c:47 (discriminator 1)
 877:	bf 20 00 00 00       	mov    $0x20,%edi
 87c:	e8 0f fd ff ff       	callq  590 <putchar@plt>
/home/runner/Assignments/bonus_assign/task1/msb.c:45 (discriminator 2)
	for(i=31;i>=0;i--) {
 881:	83 6d fc 01          	subl   $0x1,-0x4(%rbp)
/home/runner/Assignments/bonus_assign/task1/msb.c:45 (discriminator 1)
 885:	83 7d fc 00          	cmpl   $0x0,-0x4(%rbp)
 889:	79 bc                	jns    847 <print_binary+0x14>
/home/runner/Assignments/bonus_assign/task1/msb.c:49
	}
}
 88b:	90                   	nop
 88c:	c9                   	leaveq 
 88d:	c3                   	retq   
 88e:	66 90                	xchg   %ax,%ax

0000000000000890 <__libc_csu_init>:
__libc_csu_init():
 890:	41 57                	push   %r15
 892:	41 56                	push   %r14
 894:	49 89 d7             	mov    %rdx,%r15
 897:	41 55                	push   %r13
 899:	41 54                	push   %r12
 89b:	4c 8d 25 06 05 20 00 	lea    0x200506(%rip),%r12        # 200da8 <__frame_dummy_init_array_entry>
 8a2:	55                   	push   %rbp
 8a3:	48 8d 2d 06 05 20 00 	lea    0x200506(%rip),%rbp        # 200db0 <__init_array_end>
 8aa:	53                   	push   %rbx
 8ab:	41 89 fd             	mov    %edi,%r13d
 8ae:	49 89 f6             	mov    %rsi,%r14
 8b1:	4c 29 e5             	sub    %r12,%rbp
 8b4:	48 83 ec 08          	sub    $0x8,%rsp
 8b8:	48 c1 fd 03          	sar    $0x3,%rbp
 8bc:	e8 9f fc ff ff       	callq  560 <_init>
 8c1:	48 85 ed             	test   %rbp,%rbp
 8c4:	74 20                	je     8e6 <__libc_csu_init+0x56>
 8c6:	31 db                	xor    %ebx,%ebx
 8c8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 8cf:	00 
 8d0:	4c 89 fa             	mov    %r15,%rdx
 8d3:	4c 89 f6             	mov    %r14,%rsi
 8d6:	44 89 ef             	mov    %r13d,%edi
 8d9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
 8dd:	48 83 c3 01          	add    $0x1,%rbx
 8e1:	48 39 dd             	cmp    %rbx,%rbp
 8e4:	75 ea                	jne    8d0 <__libc_csu_init+0x40>
 8e6:	48 83 c4 08          	add    $0x8,%rsp
 8ea:	5b                   	pop    %rbx
 8eb:	5d                   	pop    %rbp
 8ec:	41 5c                	pop    %r12
 8ee:	41 5d                	pop    %r13
 8f0:	41 5e                	pop    %r14
 8f2:	41 5f                	pop    %r15
 8f4:	c3                   	retq   
 8f5:	90                   	nop
 8f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 8fd:	00 00 00 

0000000000000900 <__libc_csu_fini>:
__libc_csu_fini():
 900:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000000904 <_fini>:
_fini():
 904:	48 83 ec 08          	sub    $0x8,%rsp
 908:	48 83 c4 08          	add    $0x8,%rsp
 90c:	c3                   	retq   
