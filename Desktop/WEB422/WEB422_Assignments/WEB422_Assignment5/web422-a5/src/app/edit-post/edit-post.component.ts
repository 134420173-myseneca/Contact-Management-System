
import { Component, OnInit } from '@angular/core';
import { PostService } from '../post-service';
import { BlogPost } from '../../BlogPost';
import { NgForm } from '@angular/forms';
import { Router, ActivatedRoute } from '@angular/router';


@Component({
  selector: 'app-edit-post',
  templateUrl: './edit-post.component.html',
  styleUrls: ['./edit-post.component.css']
})
export class EditPostComponent implements OnInit {

  blogPost: BlogPost;
  tags: string;

  constructor(private data: PostService, private route: ActivatedRoute, private router: Router) { }

  ngOnInit(): void {
    let id = this.route.snapshot.params['id'];
    this.data.getPostByID(id).subscribe(data => {
      this.blogPost = data;
      this.tags = data.tags.toString();
    })
  }
  formSubmit(): void {
    this.blogPost.tags = this.tags.split(",").map(tag => tag.trim());
    this.data.updatePostById(this.blogPost._id, this.blogPost).subscribe(() => this.router.navigate(['/admin']));
  }
  deletePost(id): void {
    this.data.deletePostById(id).subscribe(() => this.router.navigate(['/admin']));
  }
}
