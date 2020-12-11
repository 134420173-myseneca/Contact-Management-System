import { Component, OnInit, OnDestroy } from '@angular/core';
import { PostService } from '../post-service';
import { Router } from '@angular/router';
import { BlogPost } from '../../BlogPost';

@Component({
  selector: 'app-posts-table',
  templateUrl: './posts-table.component.html',
  styleUrls: ['./posts-table.component.css']
})

export class PostsTableComponent implements OnInit, OnDestroy {

  blogPosts: Array<BlogPost> = [];
  posts: any;

  constructor(private _post: PostService, private router: Router) { }

  ngOnInit(): void {
    this.posts = this._post.getAllPosts().subscribe(_post => this.blogPosts = _post);
  }

  ngOnDestroy(): void{
    if(this.posts) this.posts.unsubscribe();
  }

  rowClicked(e, _id) {
    this.router.navigate(['/admin/post', _id]);
  }
}
